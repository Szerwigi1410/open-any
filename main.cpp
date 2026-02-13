//libs-----------------------------------------
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
//namespaces----------------------------------
using namespace std;
namespace fs = std::filesystem;
using namespace fs;

//!!! ADD TO A SEPARATE HEADER FILE LATER
// important values
// paths
string confPath = string(getenv("HOME")) + "/.config/open-any/config.txt";
//programs
string code;
string text;
string audio;
string video;
string defaultOp;

// error printing
void prnError(string s) {
	cerr << "\033[31m" << "\033[1m" << s;
}

//!!!

int main(int argc, char* argv[]) {
//------config-file-checker/creator------------------
	if (!fs::exists(confPath)) {
		system("mkdir ~/.config/open-any/");
		ofstream configMaker(confPath);
		configMaker << "vim"  << '\n'
			    << "nano" << '\n'
			    << "mpv"  << '\n'
			    << "mpv"  << '\n'
			    << "vim"  << '\n';
		configMaker.close();
	}
//------assigning-config-values-to-program-values----
	ifstream valueReader;
	valueReader.open(confPath);
	if (valueReader.fail()) {
		prnError("Couldn't read config data\n");
		return 1;
	}
	else {
		valueReader  >> code
			     >> text
			     >> audio
			     >> video
			     >> defaultOp;
	}
//------when-nothing-is-passed-----------------------
	if (argc < 2) {
		cerr << "No file name was given\n";
		return 1;
	}
//------Cool-options-with-"--"-----------------------
	string optionDashDash = argv[1];
	//getting help
	if (optionDashDash == "--help") {
		cout << "Usage:\n"
		     << "    open <file>\n"
		     << "    open --removeConf (removes the config file AND directory)\n";
		return 0;
	}
	//removing config
	if (optionDashDash == "--removeConf") {
		system("rm -rf ~/.config/open-any/");
	}
//------The-file--------------------------------------
	path theFile = argv[1];
//------Error-handling--------------------------------
	// no errors to handle (for now)
//------code-files------------------------------------
	if(theFile.extension() == ".C" || theFile.extension() == ".c" || theFile.extension() == ".cpp" || theFile.extension() == ".h" || theFile.extension() == ".hpp" || theFile.extension() == ".sh" || theFile.extension() == ".py" || theFile.extension() == ".java") {
		string opening = code + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------generic-text-files---------------------------
	else if (theFile.extension() == ".txt") {
		string opening = text + " ";
		opening += argv[1];
		system(opening.c_str());	
	}
//------audio-only-files-----------------------------
	else if (theFile.extension() == ".mp3" || theFile.extension() == ".m4a" || theFile.extension() == ".aac" || theFile.extension() == ".wav" || theFile.extension() == ".flac" || theFile.extension() == ".ogg" || theFile.extension() == ".opus" || theFile.extension() == ".aiff" || theFile.extension() == ".aif" || theFile.extension() == ".wma" || theFile.extension() == ".alac" || theFile.extension() == ".ape" || theFile.extension() == ".wv" || theFile.extension() == ".tta" || theFile.extension() == ".amr" || theFile.extension() == ".mid" || theFile.extension() == ".midi" || theFile.extension() == ".dsf" || theFile.extension() == ".dff" || theFile.extension() == ".au" || theFile.extension() == ".ra" || theFile.extension() == ".voc"
) {
		string opening = audio + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------video-files----------------------------------
	else if (theFile.extension() == ".mp4") {
		string opening = video + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------When-no-matching-extensions------------------
	else {
		string opening = defaultOp + " ";
		opening += argv[1];
		system(opening.c_str());
	}
	
	return 0;
}
