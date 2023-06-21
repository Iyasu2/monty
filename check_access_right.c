/**
  * check_access_rights - entry point
  * @filename: name of file
  *
  * Return: None
  */
void check_access_rights(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
