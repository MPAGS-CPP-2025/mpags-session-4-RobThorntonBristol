#include <boost/program_options.hpp>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    const std::string programVersion{"mpags-cipher 1.0.0"};
    std::string input_file;
    std::string output_file;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("version", "Show program version")
        ("input,i", po::value(&input_file),"Name of input file")
        ("output,o", po::value(&output_file),"Name of output file");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }
    if (vm.count("version")) {
        std::cout << programVersion << std::endl;
        return 0;
    }

    po::notify(vm);

    std::cout << "Input file: " << input_file << "\n";
    std::cout << "Output file: " << output_file << "\n";

    // const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // for (int i{1}; i < cmdLineArgs.size(); i++) {
    //     if ((cmdLineArgs[i] == "-h") || (cmdLineArgs[i] == "--help")) {
    //         std::cout << "Usage: mpags-cipher [options] ..." << std::endl;
    //         std::cout << "Options:" << std::endl;
    //         std::cout << "--help Display this information" << std::endl;
    //         std::cout << " ... " << std::endl;
    //         exit(0);
    //     } else if (cmdLineArgs[i] == "--version") {
    //         std::cout << "Version: 1.0.0" << std::endl;
    //         exit(0);
    //     }
    //     if (cmdLineArgs[i] == "-i") {
    //         std::string input_file{cmdLineArgs[i + 1]};
    //         std::cout << "Input file name: " << input_file << std::endl;
    //     }
    //     if (cmdLineArgs[i] == "-o") {
    //         std::string output_file{cmdLineArgs[i + 1]};
    //         std::cout << "Output file name: " << output_file << std::endl;
    //     }
    // }

    std::cout << "\n";
    std::cout << "Starting Cipher..." << std::endl;
    std::cout << "Enter text to encrypt: " << std::endl;

    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}