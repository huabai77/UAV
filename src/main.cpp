
#include <iostream>

int main(int argc, char* argv[])
{
   std::cout << "Start" << std::endl;

   // default configuration filename
   std::string configFilename = "config.edl";

   for (int i = 1; i < argc; i++) {
      if ( std::string(argv[i]) == "-f" ) {
         configFilename = argv[++i];
      }
   }

   std::cout << configFilename << std::endl;

   std::cout << "End" << std::endl;

   return 0;
}
