#include "PersonalFileHandler.h"
int main()
{
    FileHandler my_file("sample_file.txt");

    my_file.writeData("Heyy! Im the Admin of this file!\nAdmin is writing some content to the file");
    my_file.appendData("This content is appended to the file by the ADMIN");
    my_file.readData();
    my_file.fileCopy("sample_file.txt", "copy_file.txt");
    return 0;
}
