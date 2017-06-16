Program 1: target name = prog2_1 Reads from stdin, writes to stdout. Flags: -p to pad
-u to unpad -b<n> for block length n
Description: Reads stdin in binary format. With the -p (pad) option outputs the same data in binary format padded to a multiple of n bytes, with n=8 as the default. Padding is between 1 and n bytes appended to the end of the data, with the value of each byte (in binary) equal to the number of padding bytes. With the -u (unpad) option removes the 1 to n padding bytes and outputs the nonpad data bytes in binary format, or if the padding is incorrect, outputs an error message to stderr and may produce partial or no output to stdout; in particular, the last (partial) block may be output as read, or not output at all.

Program 2: target name = prog2_2 Reads from stdin, writes to stdout. Flags: -e for encrypt
-d for decrypt -b<n> for blocksize = n -k<filename> for file containing the key
Description: Reads in binary bytes from stdin, writes in binary to stdout. Read n bytes (default n=8) and reorder them according to the permutation given in the key file, then output that block of bytes in the permuted order. The input file must be a multiple of n bytes or else an error is output to stderr and the last block (with less than n bytes) is not output. The key file is n bytes long that encode (in binary) a permutation of n bytes, with one byte per position, and each byte a unique value in the range of 0 to n-1. Encryption (-e option): The permutation is specified by the position of the key byte, so that the ith byte of input block j is the k(i)th byte of output block j, where k(i) is the binary value of the ith byte of the keyfile, and i ranges from 0 to n-1. Decryption: The permutation is the inverse of the permutation for encryption. Hence, the key file must be read in, then the permutation inverted before applying the transposition. Error Checking: The program must check for error conditions (e.g., missing key file, key file not having a valid permutation of n bytes, not having a multiple of n bytes in the input, etc.), and report any error to stderr in a meaningful way, then exit with a non-zero exit code.

1)  VERY IMPORTANT**- Compilation/make command: in the terminal when in the directory with the source file and makefile
      type "make" to compile, then in the terminal type "./loco" to run the program(DO NOT click the loco executable, not reliable).
      after typing "./loco" the program will run properly.

2) I only have 2_1 program up and running. I have the bulk of program 2_2 in the same main file commented out.
                program 2_2: i first stored the key file in a vector then stored the file to be encrypted in another vector.
                i attempted to sort the would-be encrypted file using vector sort,using the key vector as the guide.
                unfortunately, the sort library wouldn't function properly.
                I then had the code to insert the would-be encrypted vector elements back into the file using ofstream.

3) to run program 2_1: type the name of the text file, my testing file was "example.txt".
                      then type "p" or "u", for padding and unpadding respectively.
                      finally type the padding bytes length, for example i tested the program with "8".

4) You will see results both in the terminal and in the file!!!!
