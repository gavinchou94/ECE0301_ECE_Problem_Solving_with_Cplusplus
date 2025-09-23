// program to compare two files
// returns EXIT_SUCCESS if they are identical
// returns EXIT_FAILURE if not
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    std::cout << "Usage: compare_files "
              << "<first_input_filename> <second_output_filename>"
              << std::endl;
    return EXIT_FAILURE;
  }

  try
  {
    std::ifstream input1(argv[1]);
    std::ifstream input2(argv[2]);

    if (input1.fail() || input2.fail())
    {
      std::cout << "Unable to read files." << std::endl;
      return EXIT_FAILURE;
    }

    bool ok = true;
    std::string line1, line2;
    int count = 1;
    while (getline(input1, line1) && getline(input2, line2))
    {
      // ignore carriage returns
      if (line1.find('\r') != std::string::npos)
      {
        line1 = line1.substr(0, line1.length() - 1);
      }
      if (line2.find('\r') != std::string::npos)
      {
        line2 = line2.substr(0, line2.length() - 1);
      }

      if (line1.length() != line2.length())
      {
        ok = false;
        break;
      }
      for (int i = 0; i < line1.length(); i++)
      {
        if (line1[i] != line2[i])
        {
          ok = false;
          break;
        }
      }

      if (!ok)
      {
        break;
      }
      count++;
    }

    if (!ok)
    {
      std::cout << "Files differ." << std::endl;
      std::cout << "File 1 line " << count << " is: " << line1 << std::endl;
      std::cout << "File 2 line " << count << " is: " << line2 << std::endl;
      return EXIT_FAILURE;
    }

    // check files are the same length
    getline(input1, line1);
    getline(input2, line2);
    if (!input1.eof() || !input2.eof())
    {
      std::cout << "Files differ in length." << std::endl;
      std::cout << "File 1 line " << count << " is: " << line1 << std::endl;
      std::cout << "File 2 line " << count << " is: " << line2 << std::endl;
      return EXIT_FAILURE;
    }
  }
  catch (std::exception &ex)
  {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Files identical." << std::endl;
  return EXIT_SUCCESS;
}