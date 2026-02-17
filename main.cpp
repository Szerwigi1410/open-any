//libs-----------------------------------------
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
//my-headers---------------------------------
#include "stuff.h"
//namespaces----------------------------------
using namespace std;
namespace fs = std::filesystem;
using namespace fs;

//main-code------------------------------------------
int main(int argc, char* argv[]) {
//------config-file-checker/creator------------------
	if (!fs::exists(confPath)) {
		system("mkdir ~/.config/open-any/");
		ofstream configMaker(confPath);
		configMaker << "vim"   << '\n' //1
			    << "nano"  << '\n' //2
			    << "mpv"   << '\n' //3
			    << "mpv"   << '\n' //4
			    << "emacs" << '\n' //5
			    << "feh"   << '\n' //6
			    << "gimp"  << '\n' //7
			    << "krita" << '\n' //8
			    << "vim"   << '\n';//9
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
		valueReader  >> code 	   //1
			     >> text       //2
			     >> audio	   //3
			     >> video	   //4
			     >> mdown	   //5
			     >> pics 	   //6
			     >> gimp 	   //7
			     >> krita	   //8
			     >> defaultOp; //9
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
		     << "    open --removeConf (removes the config file AND directory)\n"
		     << "    open --editConf (opens the config file in vim)\n";
		return 0;
	}
	//removing config
	if (optionDashDash == "--removeConf") {
		system("rm -rf ~/.config/open-any/");
	}
	//getting to config
	if (optionDashDash == "--editConf") {
		system("vim ~/.config/open-any/config.txt");
	}
//------The-file--------------------------------------
	path theFile = argv[1];
//------Error-handling--------------------------------
	// no errors to handle (for now)
//------code-files------------------------------------
	if(theFile.extension() == ".C" || theFile.extension() == ".c" || theFile.extension() == ".cc" || theFile.extension() == ".cpp" || theFile.extension() == ".cxx" || theFile.extension() == ".h" || theFile.extension() == ".hh" || theFile.extension() == ".hpp" || theFile.extension() == ".hxx" || theFile.extension() == ".sh" || theFile.extension() == ".bash" || theFile.extension() == ".zsh" || theFile.extension() == ".py" || theFile.extension() == ".pyw" || theFile.extension() == ".java" || theFile.extension() == ".js" || theFile.extension() == ".ts" || theFile.extension() == ".rs" || theFile.extension() == ".go" || theFile.extension() == ".rb" || theFile.extension() == ".php" || theFile.extension() == ".cs" || theFile.extension() == ".swift" || theFile.extension() == ".kt" || theFile.extension() == ".kts" || theFile.extension() == ".scala" || theFile.extension() == ".dart" || theFile.extension() == ".lua" || theFile.extension() == ".pl" || theFile.extension() == ".r" || theFile.extension() == ".m" || theFile.extension() == ".mm" || theFile.extension() == ".sql" || theFile.extension() == ".asm"
) {
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
	else if (theFile.extension() == ".mp4" || theFile.extension() == ".mov" || theFile.extension() == ".mkv" || theFile.extension() == ".avi") {
		string opening = video + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------Mark-down------------------------------------
	else if(theFile.extension() == ".md") {
		string opening = mdown + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------Pictures-------------------------------------
	else if(theFile.extension() == ".png" || theFile.extension() == ".apng" || theFile.extension() == ".jpg" || theFile.extension() == ".jpeg" || theFile.extension() == ".jpe" || theFile.extension() == ".jfif"
) {
		string opening = pics + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------GIMP-----------------------------------------
	else if(theFile.extension() == ".xcf") {
		string opening = gimp + " ";
		opening += argv[1];
		system(opening.c_str());
	}
//------Krita----------------------------------------
	else if(theFile.extension() == ".kra") {
                 string opening = krita + " ";
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
