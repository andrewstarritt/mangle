/* mangle.c
 *
 * Copyright (c) 2013,2017,2018 Andrew Starritt
 *
 * The mangle program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The mangle program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the mangle program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Andrew Starritt
 * Contact details:  starritt@netspace.net.au
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MANGLE_VERSION_STRING  "1.1.2"

/*------------------------------------------------------------------------------
 */
static void usage (FILE *stream)
{
   fprintf (stream, "usage: mangle [input_file [output_file]]\n");
   fprintf (stream, "       mangle -h | --help\n");
}

/*------------------------------------------------------------------------------
 */
static void help ()
{
   fprintf (stdout, "mangle %s\n", MANGLE_VERSION_STRING);
   fprintf (stdout, "\n");
   usage   (stdout);
   fprintf (stdout, "\n");
   fprintf (stdout, "mangle mangles a file or standard input to a file or standard output.\n");
   fprintf (stdout, "Note mangle is not cyrptographically secure - that's not its purpose.\n");
   fprintf (stdout, "mangle is the binary equivilent of ROT13 - it does just enough to fool\n");
   fprintf (stdout, "those pesky e-mail filters.\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "mangle an involutory program, i.e. it also de-mangles as mangle is its\n");
   fprintf (stdout, "own inverse:\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "   mangle  foo bar\n");
   fprintf (stdout, "   mangle  bar recovered_foo\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "foo and recovered_foo are identical, bar is a \"mess\".\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "Options\n");
   fprintf (stdout, "--help, -h   print this help information and exit.\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "Parameters\n");
   fprintf (stdout, "input_file   the file to be mangled/demangled. When no input file specified, or\n");
   fprintf (stdout, "             just '-' specified, the input is taken from standard input.\n");
   fprintf (stdout, "\n");
   fprintf (stdout, "output_file  target demangled/mangled file. When no output file specified, or\n");
   fprintf (stdout, "             just '-' specified, the output is sent to standard output.\n");
   fprintf (stdout, "\n");
}


/*------------------------------------------------------------------------------
 */
static int mangle_it (const int fdin, const int fdout)
{
   unsigned char buffer[8192];
   ssize_t bytes_read;
   /* ssize_t bytes_written; */
   int j;


   for (;;) {
      bytes_read = read (fdin, buffer, sizeof (buffer));

      if (bytes_read == 0) {
         break;                 /* all done */
      }

      if (bytes_read < 0) {
         perror ("");
         return (-1);
      }

      /* Not cyrptographically secure - that not the intension.
       * What mangle is up-to is just enough to fool those e-mail filters.
       */
      for (j = 0; j < bytes_read; j++) {
         buffer[j] ^= 0xFF;
      }

      /* bytes_written = */
      write (fdout, buffer, bytes_read);

   }
   return 0;
}      /* mangle_it */


/*------------------------------------------------------------------------------
 */
int main (int argc, char *argv[])
{
   int paramc;
   char message[200];
   int fdin;
   int fdout;
   int status;

   paramc = argc - 1;

   if (paramc >= 1) {
      if ( (strcmp (argv [1], "--help") == 0) ||
           (strcmp (argv [1], "-h") == 0) ) {
         help ();
         return 0;
      }
   }

   if (paramc >= 3) {
      fprintf (stderr, "unexpected number of arguments\n");
      usage (stderr);
      return 1;
   }

   /* std in to std out - the default
    */
   fdin = 0;
   fdout = 1;

   if (paramc >= 1) {
      if (strcmp (argv[1], "-") != 0) {
         fdin = open (argv[1], O_RDONLY);
         if (fdin < 0) {
            snprintf (message, sizeof (message),
                      "failed open input file '%s' ", argv[1]);
            perror (message);
            return 1;
         }
      }
   }

   if (paramc >= 2) {
      if (strcmp (argv[2], "-") != 0) {
         fdout = creat (argv[2], S_IRUSR | S_IWUSR);
         if (fdout < 0) {
            snprintf (message, sizeof (message),
                      "failed create output file '%s' ", argv[2]);
            perror (message);
            return 1;
         }
      }
   }

   if (fdout != 1) {
      fprintf (stdout, "mangle %s\n", MANGLE_VERSION_STRING);
   }

   status = mangle_it (fdin, fdout);

   return status;
}

/* end*/
