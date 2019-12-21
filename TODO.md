* Add prefix to **clibs**
* `cio` module for C string, i.e. null-terminated `char` array
  * `read_line` function to read stream line by line
  * `read_all` function to read all text from stream
  * `write_line` function to write a line of text into stream
  * `write_all` function to write all text into stream
* `path` module for file path cross Windows and Unix
  * `base_name` function to get base name of a file path
  * `dir_name` function to get directory name of a file path
  * `ext_name` function to get file extension of a file path
