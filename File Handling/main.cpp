#include "PersonalFileHandler.h"
int main()
{
    FileHandler my_file("sample_file.txt");

    my_file.writeToFile("Heyy! Im the Admin of this file!\nAdmin is writing some content to the file");
    my_file.appendToFile("This content is appended to the file by the ADMIN");
    my_file.readFromFile();
    my_file.fileCopy("sample_file.txt", "copy_file.txt");
    return 0;
}
