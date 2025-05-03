#include <iostream>
#include <complex>
#include <Windows.h>
#include <winuser.h>
#include <Lmcons.h>
#include <time.h>
#include <fstream>
#include <shlobj.h>
#include <tchar.h>
using namespace std;

//classes.h starts here.

class Element {
private:
    char* password;
    char* website;
public:
    Element(char*, char*);
    Element(Element*);

    char* getPassword();
    char* getWebsite();

    void setPassword(char*);
    void setWebsite(char*);
};

class Password_Setup {
private:
    int style;
    int num;
    char* code;
    char let;

    char* pw;
public:
    Password_Setup();
    Password_Setup(string);

    char* getPassword();

    void setPassword(char*);
    void setPassword(string);

    char* appendChar(char*, char);
    char* toUpperCase(string);
    char* attach(char*);

    bool identification();
    char* encryption(string);
    char* decryption(char*, char*, string);
    char loop_Chars(char, int, bool);
    char loop_Nums(int, int, bool);

    void txtOutput(HANDLE, int, bool, string);
};

class List {
private:
    int anzahl;
    int Max;

    Element** Index;
public:
    List(int);

    int getMax();
    char* getIndexPassword(int);
    char* getIndexWebsite(int);

    void anhang(Element*);
    int suche(string);
    void display();
    void loeschen(int, string);

    void vertausche(int, int);
    int part(int, int);
    void quickSort(int, int);
};

class Files {
private:
    string FILE_PATH;
public:
    Files(string);

    string getFILE_PATH();
    void setFILE_PATH(string);

    int file_Count();
    List* file_Load();
    void file_Save(string, char*, List*);
};


// classes.cpp starts here

Element::Element(char* pw, char* web): password(pw), website(web) {}
Element::Element(Element* cop): password(cop->getPassword()), website(cop->getWebsite()) {}

char* Element::getPassword() {
    return this->password;
}

char* Element::getWebsite() {
    return this->website;
}

void Element::setPassword(char* s) {
    this->password = s;
}

void Element::setWebsite(char* s) {
    this->website = s;
}

Password_Setup::Password_Setup(): style(0), num(0), code(NULL), let(NULL), pw("") {}
Password_Setup::Password_Setup(string website): style(0), num(0), code(NULL), let(NULL), pw(NULL) {

    // Password triplet creation
    char* web = "";
    char* website_Upper = this->toUpperCase(website);

    for (int i = 0; i < 3; i++) {
        web = this->appendChar(web, website_Upper[i]);
    }

    // Style generation
    srand(time(NULL)); // A new generation every time the program starts; random seed

    this->style = rand() % 3 + 1;

    // Number generation
    for (int j = 0; j < 3; j++) {
        int n = rand() % 9 + 1;

        if (j == 0) {
            this->num += n * 100;
        } else if (j == 1) {
            this->num += n * 10;
        } else {
            this->num += n;
        }
    }

    // Code generation
    this->code = "";

    for (int k = 0; k < 7; k++) {
        int num = 0;
        int area = rand() % 2;

        if (area == 0) {
            num = rand() % 26 + 65;
        } else {
            num = rand() % 26 + 97;
        }

        this->code = this->appendChar(this->code, num);
    }

    // Generation of the character
    int select = rand() % 2;

    if (select == 0) {
        this->let = '$';
    } else {
        this->let = '%';
    }

    // Composition of the password
    this->pw = this->attach(web);
}

char* Password_Setup::getPassword() {
    return this->pw;
}

void Password_Setup::setPassword(char* s) {
    this->pw = s;
}

void Password_Setup::setPassword(string s) {
    for (int i = 0; i < s.size(); i++) {
        this->pw = this->appendChar(this->pw, s[i]);
    }
}

char* Password_Setup::appendChar(char* arr, char a) {
    size_t len = strlen(arr);

    char* ret = new char[len + 2];

    strcpy(ret, arr);
    ret[len] = a;
    ret[len + 1] = '\0';

    return ret;
}

char* Password_Setup::toUpperCase(string website) {
    char* website_Upper = "";

    for (int i = 0; i < website.size(); i++) {
        int check_n = website[i];
        char check_c;

        if (check_n >= 97 && check_n <= 122) {
            check_n -= 32;
        }
        check_c = check_n;

        website_Upper = this->appendChar(website_Upper, check_c);
    }

    return website_Upper;
}

char* Password_Setup::attach(char* web) {
    char* output = "";

    ostringstream ostr; // Conversion from int to string
    ostr << this->num;
    string num = ostr.str();

    if (this->style == 1) { // code + let + num + WEB
        for (int i = 0; i < 10; i++) {
            if (i < 7) {
                output = this->appendChar(output, this->code[i]);
            } else if (i == 7) {
                output = this->appendChar(output, this->let);
            } else if (i == 8) {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, num[j]);
                }
            } else {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, web[j]);
                }
            }
        }

        return output;
    } else if (this->style == 2) { // code + num + let + WEB
        for (int i = 0; i < 10; i++) {
            if (i < 7) {
                output = this->appendChar(output, this->code[i]);
            } else if (i == 7) {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, num[j]);
                }
            } else if (i == 8) {
                output = this->appendChar(output, this->let);
            } else {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, web[j]);
                }
            }
        }

        return output;
    } else { // num + let + code + WEB
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, num[j]);
                }
            } else if (i == 1) {
                output = this->appendChar(output, this->let);
            } else if (i < 9) {
                output = this->appendChar(output, this->code[i - 2]);
            } else {
                for (int j = 0; j < 3; j++) {
                    output = this->appendChar(output, web[j]);
                }
            }
        }

        return output;
    }
}

bool Password_Setup::identification() {
    int check = this->pw[0]; //first place
    int check_n;

    if ((check >= 65 && check <= 90) || (check >= 97 && check <= 122)) { // Letters first -> Style 1,2
        for (int i = 1; i < 7; i++) {
            check_n = this->pw[i];

            if (!(check_n >= 65 && check_n <= 90) && !(check_n >= 97 && check_n <= 122)) {
                return false;
            }
        } // all letters found, now check if character or number

        check_n = this->pw[7];
        if (check_n == 36 || check_n == 37) { // Signs? -> Look for numbers
            for (int i = 8; i < 11; i++) {
                check_n = this->pw[i];

                if (!(check_n >= 48 && check_n <= 57)) {
                    return false;
                }
            }

            this->style = 1;
        } else if (check_n >= 48 && check_n <= 57) { // Numbers? -> Look for characters
            for (int i = 8; i < 11; i++) {
                check_n = this->pw[i];

                if (i < 10) { // two more numbers
                    if (!(check_n >= 48 && check_n <= 57)) {
                        return false;
                    }
                } else { // Sign
                    if (!(check_n == 36 || check_n == 37)) {
                        return false;
                    }
                }
            }

            this->style = 2;
        } else {
            return false;
        }
    } else if (check >= 48 && check <= 57) { // Numbers first -> Style 3
        for (int i = 1; i < 11; i++) {
            check_n = this->pw[i];

            if (i < 3) { // two numbers
                if (!(check_n >= 48 && check_n <= 57)) {
                    return false;
                }
            } else if (i == 3) { // Sign
                if (!(check_n == 36 || check_n == 37)) {
                    return false;
                }
            } else { //7 letters
                if (!(check_n >= 65 && check_n <= 90) && !(check_n >= 97 && check_n <= 122)) {
                    return false;
                }
            }
        }

        this->style = 3;
    } else {
        return false;
    }

    return true; // = true,if no errors
}

char* Password_Setup::encryption(string KEY) {
    int i, key_part;
    char* encrypted = "";

    if (this->style == 1) {
        for (i = 0; i < 7; i++) {
            if (i < 2) {
                key_part = KEY[2] - 64;
            } else if (i < 5) {
                key_part = KEY[1] - 64;
            } else {
                key_part = KEY[0] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Chars(this->pw[i], key_part, true));
        }

        encrypted = this->appendChar(encrypted, this->pw[i]);

        for (i += 1; i < 11; i++) {
            if (i == 9) {
                key_part = KEY[0] - 64;
            } else {
                key_part = KEY[2] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Nums(this->pw[i] - 48, key_part, true));
        }

        for (i = 11; i < 14; i++) {
            encrypted = this->appendChar(encrypted, this->pw[i]);
        }
    } else if (this->style == 2) {
        for (i = 0; i < 7; i++) {
            if (i < 2) {
                key_part = KEY[1] - 64;
            } else if (i < 5) {
                key_part = KEY[2] - 64;
            } else {
                key_part = KEY[0] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Chars(this->pw[i], key_part, true));
        }

        for (i += 0; i < 10; i++) {
            if (i == 9) {
                key_part = KEY[1] - 64;
            } else {
                key_part = KEY[2] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Nums(this->pw[i] - 48, key_part, true));
        }

        encrypted = this->appendChar(encrypted, this->pw[i]);

        for (i = 11; i < 14; i++) {
            encrypted = this->appendChar(encrypted, this->pw[i]);
        }
    } else {
        for (i= 0; i < 3; i++) {
            if (i == 2) {
                key_part = KEY[2] - 64;
            } else {
                key_part = KEY[0] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Nums(this->pw[i] - 48, key_part, true));
        }

        encrypted = this->appendChar(encrypted, this->pw[i]);

        for (i += 1; i < 11; i++) {
            if (i < 6) {
                key_part = KEY[0] - 64;
            } else if (i < 9) {
                key_part = KEY[1] - 64;
            } else {
                key_part = KEY[2] - 64;
            }
            encrypted = this->appendChar(encrypted, loop_Chars(this->pw[i], key_part, true));
        }
        for (i = 11; i < 14; i++) {
            encrypted = this->appendChar(encrypted, this->pw[i]);
        }
    }

    cout << endl;
    cout << "Password successfully saved and encrypted!" << endl;
    return encrypted;
}

char* Password_Setup::decryption(char* encrypted, char* web, string KEY) {
    int i, key_part;
    int char_check = encrypted[0], num_check = encrypted[10];
    char* decrypted = "";

    if ((char_check >= 65 && char_check <= 122) && (num_check >= 48 && num_check <= 57)) {
        for (i = 0; i < 7; i++) {
            if (i < 2) {
                key_part = KEY[2] - 64;
            } else if (i < 5) {
                key_part = KEY[1] - 64;
            } else {
                key_part = KEY[0] - 64;
            }
            decrypted = this->appendChar(decrypted, loop_Chars(encrypted[i], key_part, false));
        }

        decrypted = this->appendChar(decrypted, encrypted[i]);

        for (i += 1; i < 11; i++) {
            if (i == 9) {
                key_part = KEY[0] - 64;
            } else {
                key_part = KEY[2] - 64;
            }
            decrypted = this->appendChar(decrypted, loop_Nums(encrypted[i] - 48, key_part, false));
        }

        for (i = 0; i < 3; i++) {
            decrypted = this->appendChar(decrypted, web[i]);
        }
    } else if ((char_check >= 65 && char_check <= 122) && (num_check < 48)) {
            for (i = 0; i < 7; i++) {
				if (i < 2) {
					key_part = KEY[1] - 64;
				} else if (i < 5) {
					key_part = KEY[2] - 64;
				} else {
					key_part = KEY[0] - 64;
				}

				decrypted = this->appendChar(decrypted, loop_Chars(encrypted[i], key_part, false));
			}

			for (i += 0; i < 10; i++) {
				if (i == 9) {
					key_part = KEY[1] - 64;
				} else {
					key_part = KEY[2] - 64;
				}

				decrypted = this->appendChar(decrypted, loop_Nums(encrypted[i] - 48, key_part, false));
			}
			decrypted = this->appendChar(decrypted, encrypted[i]);

        for (i = 0; i < 3; i++) {
            decrypted = this->appendChar(decrypted, web[i]);
        }
    } else {
            for (i = 0; i < 3; i++) {
				if (i == 2) {
					key_part = KEY[2] - 64;
				} else {
					key_part = KEY[0] - 64;
				}

				decrypted = this->appendChar(decrypted, loop_Nums(encrypted[i] - 48, key_part, false));
			}

			decrypted = this->appendChar(decrypted, encrypted[i]);

			for (i += 1; i < 11; i++) {
				if (i < 6) {
					key_part = KEY[0] - 64;
				} else if (i < 9) {
					key_part = KEY[1] - 64;
				} else {
					key_part = KEY[2] - 64;
				}

				decrypted = this->appendChar(decrypted, loop_Chars(encrypted[i], key_part, false));
			}

            for (i = 0; i < 3; i++) {
                decrypted = this->appendChar(decrypted, web[i]);
            }
    }

    return decrypted;
}

char Password_Setup::loop_Chars(char c, int key, bool encr_decr) { // true = encryption / false = decryption
    if (encr_decr) {
        int character = c;
        character += key;

        if (character > 122) {
			int checkpoint = character - 122;
			character = 64 + checkpoint;
		}

		return character;
    } else {
        int character = c;
		character -= key;

        if (character < 65) {
			int checkpoint = character + 122;
			character = checkpoint - 64;
		}

		return character;
    }
}

char Password_Setup::loop_Nums(int i, int key, bool encr_decr) {
    char character;

    if (encr_decr) {
		if (key >= 20) {
			i += 8;
		} else if (key >= 14) {
			i += 4;
		} else if (key >= 5) {
			i += 6;
		} else {
			i += 1;
		}

		if (i > 9) {
			i -= 10;
		}

		character = i + 48;

		return character;
    } else {
		if (key >= 20) {
			if (i >= 8) {
				i -= 8;
			} else {
				i += 2;
			}
		} else if (key >= 14) {
			if (i >= 4) {
				i -= 4;
			} else {
				i += 6;
			}
		} else if (key >= 5) {
			if (i >= 6) {
				i -= 6;
			} else {
				i += 4;
			}
		} else {
			if (i >= 1) {
				i -= 1;
			} else {
				i += 9;
			}
		}

		character = i + 48;

		return character;
    }
}

void Password_Setup::txtOutput(HANDLE console, int color, bool line, string text) {
    SetConsoleTextAttribute(console, color); //1 blue //2 green //3 light blue //4 red //5 purple //6 gold //7 silver // 15 white
    if (line) {
        cout << text << endl;
    } else {
        cout << text;
    }
    SetConsoleTextAttribute(console, 15); //back to default (white)
}

List::List(int anzahl): anzahl(0), Max(anzahl - 2), Index(NULL) {
    this->Index = (Element**) malloc(anzahl * sizeof(Element*));
}

int List::getMax() {
    return this->Max;
}

char* List::getIndexPassword(int stelle) {
    return this->Index[stelle]->getPassword();
}

char* List::getIndexWebsite(int stelle) {
    return this->Index[stelle]->getWebsite();
}

void List::anhang(Element* neu) {
    this->Index[anzahl] = neu;
    this->anzahl++;
}

int List::suche(string website) {
    Password_Setup* methods;
    char* website_toUpper = "";
    website_toUpper = methods->toUpperCase(website);

    int read = 0;
    int length = 1;
    int i;

    for (int j = 0; j <= this->Max; j++) {
        while (Index[j]->getWebsite()[read] != NULL) {
            read++;
        }

        length = read;
        read = 0;

        for (i = 0; i < length; i++) {
            if (Index[j]->getWebsite()[i] == website_toUpper[i]) {
                read++;
            }
        }

        if (read == length) {
            return j;
        } else {
            read = 0;
        }
    }

    return -1;
}

void List::display() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;
    if (this->anzahl-1 > 0) {
        if (this->anzahl-1 == 1 && this->suche(".W") != -1) {
            cout << "Error; No passwords exist! Return to the menu..." << endl;
        } else {
            Password_Setup* methods;
            char* existing_letters = "";
            int existing_letters_amount = 0;

            for (int i = 0; i <= this->Max; i++) {
                char* web = "";
                char* website = this->Index[i]->getWebsite();
                char* password = this->Index[i]->getPassword();
                bool existing_letter = false;
                string str_web = "";

                for (int j = 0; j < 3; j++) {
                    web = methods->appendChar(web, website[j]);
                }

                if (web[0] != '.') {
                    for (int i = 0; i < existing_letters_amount + 1; i++) {
                        if (website[0] == existing_letters[i]) {
                            existing_letter = true;
                        }
                    }

                    if (!existing_letter) {
                        str_web.append(website, 1);
                        methods->txtOutput(hConsole, 6, true, str_web);
                        str_web = "";
                    }

                    cout << "   " << website << ": " << password << web << endl;

                    existing_letters = methods->appendChar(existing_letters, website[0]);
                    existing_letters_amount++;
                }
            }
        }
    } else {
        cout << "Error; No passwords exist! Return to the menu..." << endl;
    }
}

void List::loeschen(int stelle, string path) {
    ofstream fileWrite;
    int more = this->anzahl - stelle;
    string deleted_website = Index[stelle]->getWebsite();

    for (int i = 0; i < more; i++) {
        Index[stelle + i] = Index[stelle + 1 + i];
    }

    this->anzahl--;

    DWORD attributes = GetFileAttributes(path.c_str());
    SetFileAttributes(path.c_str(), attributes & FILE_ATTRIBUTE_NORMAL);
    fileWrite.open(path.c_str());

    for (int i = 0; i < this->anzahl - 1; i++) {
            fileWrite << this->getIndexPassword(i) << ";" << this->getIndexWebsite(i) << endl;
    }

    cout << "Website password '" << deleted_website <<"' successfully deleted!" << endl;
}

void List::vertausche(int first, int second) {
    Element* temp = new Element(this->Index[first]);
    this->Index[first] = this->Index[second];
    this->Index[second] = temp;
}

void List::quickSort(int low, int high) {
    if (low < high) {
        int pivot = this->part(low, high);
        this->quickSort(low, pivot - 1);
        this->quickSort(pivot + 1, high);
    }
}

int List::part(int low, int high) {
    char* compare = this->Index[high]->getWebsite();
    char* compare_object = "";

    long i = low - 1;
    long j;

	 for (j = low; j <= high; j++) {
	     compare_object = this->Index[j]->getWebsite();

		 if (strcmp(compare, compare_object) > 0) {
            i++;

            vertausche(i, j);
		 }
	 }

    vertausche(i + 1, high);

    return (i + 1);
}

Files::Files(string path): FILE_PATH(path) {}

string Files::getFILE_PATH() {
    return this->FILE_PATH;
}

void Files::setFILE_PATH(string s) {
    this->FILE_PATH = s;
}

int Files::file_Count() {
    ifstream fileRead(this->getFILE_PATH().c_str());

    if (fileRead.good()) {
        DWORD attributes = GetFileAttributes(this->getFILE_PATH().c_str());
        SetFileAttributes(this->getFILE_PATH().c_str(), attributes | FILE_ATTRIBUTE_HIDDEN);

        int counter = 0;
        string pw = "";

        while (fileRead.good()) {
            getline(fileRead, pw, ';');
            counter++;
        }

        return counter - 1;
    } else {
        ofstream fileCreate(this->getFILE_PATH().c_str());
        fileCreate.open(this->getFILE_PATH().c_str());

        DWORD attributes = GetFileAttributes(this->getFILE_PATH().c_str());
        SetFileAttributes(this->getFILE_PATH().c_str(), attributes | FILE_ATTRIBUTE_HIDDEN);

        return 0;
    }
}

List* Files::file_Load() {
    int amount = this->file_Count();

    ifstream fileRead(this->getFILE_PATH().c_str());

    string pw = "", web = "";
    char* conv_PW, *conv_WEB;

    Element* neu = NULL;
    List* ret = new List(amount + 1);

    if (amount > 0) {
        while (fileRead.good()) {
            getline(fileRead, pw, ';');
            getline(fileRead, web, '\n');

            conv_PW = new char[pw.length()];
            conv_WEB = new char[web.length()];

            for(int i = 0; i <= pw.length(); i++) {
                    conv_PW[i] = pw[i];
                }

            for(int i = 0; i <= web.length(); i++) {
                    conv_WEB[i] = web[i];
                }

            neu = new Element(conv_PW, conv_WEB);
            ret->anhang(neu);
        }
    }

    fileRead.close();
    return ret;
}

void Files::file_Save(string website, char* encrypted, List* liste) {
    ofstream fileWrite;
    string line = "";

    Password_Setup* methods;

    char* website_toUpper = "";
    website_toUpper = methods->toUpperCase(website);

    line.append(encrypted, 11);
    line.append(";");
    line.append(website_toUpper);

    DWORD attributes = GetFileAttributes(this->getFILE_PATH().c_str());
    SetFileAttributes(this->getFILE_PATH().c_str(), attributes & FILE_ATTRIBUTE_NORMAL);

    fileWrite.open(this->getFILE_PATH().c_str());

    for (int i = 0; i < liste->getMax() + 2; i++) {
        if (i <= liste->getMax()) {
            fileWrite << liste->getIndexPassword(i) << ";" << liste->getIndexWebsite(i) << endl;
        } else {
            fileWrite << line << endl;
        }
    }

    fileWrite.close();
}


//main.cpp starts here


void toClipboard(HWND hwnd, const string &s);

int main()
{
    HWND hwnd = GetDesktopWindow();

    char username[UNLEN+1];
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string path = "";
    int Username_Length = 0;

    for (int i = 0; i < UNLEN+1; i++) {
        int check = username[i];

        if ((check >= 48 && check <= 57) || (check >= 65 && check <= 90) || (check >= 97 && check <= 122)) {
            Username_Length++;
        } else {
            break;
        }
    }

    for (int i = 0; i < Username_Length; i++) {
        path.append(1, username[i]);
    }

    Password_Setup* pw;
    Files* files = new Files(path.append("PW.dat"));

    char* output = "";
    int input = 0, confirm = 0;
    string website, KEY;

    pw->txtOutput(hConsole, 14, true, " __________________________________________________ ");
    pw->txtOutput(hConsole, 14, true, "| Version 1.0 @ Rezwan Ahmed Ratul                 |");

    while (true) {
        List* liste = files->file_Load();
        liste->quickSort(0, liste->getMax());

        pw->txtOutput(hConsole, 15, true, " __________________________________________________ ");
        pw->txtOutput(hConsole, 15, true, "|                   MAIN MENU:                     |");
        pw->txtOutput(hConsole, 15, true, "| (1) Decrypt existing password                    |");
        pw->txtOutput(hConsole, 15, true, "| (2) Generate and encrypt a new password          |");
        pw->txtOutput(hConsole, 15, true, "| (3) Add your own password                        |");
        pw->txtOutput(hConsole, 15, true, "| (4) Display all encrypted passwords              |");
        pw->txtOutput(hConsole, 15, true, "| (5) Delete existing password                     |");
        pw->txtOutput(hConsole, 15, true, "| (6) Finish                                       |");
        pw->txtOutput(hConsole, 15, true, "|__________________________________________________|");

        pw->txtOutput(hConsole, 2, false, "=> ");
        cin >> input;

        if (!cin.fail()) {
            while (!(1 <= input <= 6)) {
                cin >> input;
            }
        } else {
            cout << "Error; Please operate the menu with appropriate numeric inputs!" << endl;
            cin.clear();
            cin.sync();
        }

        switch(input) {
        case 1:
            {
                cin.ignore();
                cout << "Enter the name of the website whose password you need." << endl;

                do {
                    pw->txtOutput(hConsole, 2, false, "=> ");
                    getline(cin, website);

                    if (website.size() < 3) {
                        cout << "Error; Website name is too short. Try again." << endl;
                    }
                } while(website.size() < 3);

                if (liste->suche(website) == -1) {
                    cout << "Error; Website could not be found! Return to menu..." << endl;
                } else {
                    bool loop = true;
                    cout << "Enter your 3-digit key in capital letters for decryption." << endl;
                        do {
                            pw->txtOutput(hConsole, 2, false, "=> ");
                            getline(cin, KEY);

                            if (KEY.size() != 3) {
                                cout << "Error; Invalid key length! Please try again." << endl;
                            } else {
                                loop = false;

                                for (int i = 0; i < 3; i++) {
                                    int check_n = KEY[i];

                                    if (check_n < 65 || check_n > 90) {
                                        cout << "Error; Invalid key format! Please try again." << endl;
                                        loop = true;
                                        break;
                                    }
                                }
                            }
                        } while(loop);

                    output = pw->decryption(liste->getIndexPassword(liste->suche(website)), liste->getIndexWebsite(liste->suche(website)), KEY);

                    cout << "Your decrypted password (Key: " << KEY << ") is: ";
                    pw->txtOutput(hConsole, 11, true, string(output));

                    toClipboard(hwnd, (string) output);
                }

                website.clear();
                KEY.clear();
                break;
            }
        case 2:
            {
                cin.ignore();
                cout << "Enter the name of the website for which you want to generate a password." << endl;

                do {
                    pw->txtOutput(hConsole, 2, false, "=> ");
                    getline(cin, website);

                    if (website.size() < 3) {
                        cout << "Error; Website name is too short. Try again." << endl;
                    }
                } while(website.size() < 3);

                if (liste->suche(website) != -1) {
                    cout << "Error; Website already exists! Return to menu..." << endl;
                } else {
                    do {
                        pw = new Password_Setup(website);

                        cout << endl;
                        cout << pw->getPassword() << endl;
                        cout << "Are you satisfied with this generated password? (Accept with '1'; Reject with Other)" << endl;

                        pw->txtOutput(hConsole, 2, false, "=> ");

                        cin >> confirm;

                        if (cin.fail()) { // In addition to other numeric input, letters may also be used
                            cin.clear();
                            cin.sync();
                        }
                    } while (confirm != 1);

                    cin.ignore();
                    cout << "Enter a 3-digit key in capital letters for encryption." << endl;

                    do {
                        pw->txtOutput(hConsole, 2, false, "=> ");
                        getline(cin, KEY);

                        if (KEY.size() != 3) {
                            cout << "Error; Invalid key length! Please try again." << endl;
                        } else {
                            int i;

                            for (i = 0; i < 3; i++) {
                                int check_n = KEY[i];

                                if (check_n < 65 || check_n > 90) {
                                    cout << "Error; Invalid key format! Please try again." << endl;
                                    break;
                                }
                            }

                            if (i == 3) {
                                break;
                            }
                        }
                    } while(true);

                    char* encrypted = pw->encryption(KEY);

                    cout << "Your encrypted password (KEY:" << KEY << ") is: ";
                    pw->txtOutput(hConsole, 11, true, string(encrypted));

                    files->file_Save(website, encrypted, liste);
                }

                website.clear();
                KEY.clear();
                break;
            }
        case 3:
            {
                Password_Setup* custom_pw = new Password_Setup();
                string passw = "";

                cin.ignore();
                cout << "Enter the name of the website for which you want to add a password." << endl;

                do {
                    pw->txtOutput(hConsole, 2, false, "=> ");
                    getline(cin, website);

                    if (website.size() < 3) {
                        cout << "Error; Website name is too short. Try again." << endl;
                    }
                } while(website.size() < 3);

                if (liste->suche(website) != -1) {
                        cout << "Error; Website already exists! Return to menu..." << endl;
                } else {
                    cout << "Enter a default password to encrypt and save it." << endl;
                    cout << "Formats: (AAAAAAA$111), (111$AAAAAAA), (AAAAAAA111$)" << endl;

                    pw->txtOutput(hConsole, 2, false, "=> ");
                    getline(cin, passw);

                    if (passw.size() != 11) {
                        cout << "Error; Password must be 11 characters long. Please note the format! Return to the menu..." << endl;
                        break;
                    } else {
                        char* website_Upper = pw->toUpperCase(website);

                        for (int i = 0; i < 3; i++) {
                            passw.append(1, website_Upper[i]);
                        }

                        custom_pw->setPassword(passw);

                        if (custom_pw->identification()) {

                            cout << "Enter a 3-digit key in capital letters for encryption." << endl;

                            do {
                                pw->txtOutput(hConsole, 2, false, "=> ");
                                getline(cin, KEY);

                                if (KEY.size() != 3) {
                                    cout << "Error; Invalid key length! Please try again." << endl;
                                } else {
                                    int i;

                                    for (i = 0; i < 3; i++) {
                                        int check_n = KEY[i];

                                        if (check_n < 65 || check_n > 90) {
                                            cout << "Error; Invalid key format! Please try again." << endl;
                                            break;
                                        }
                                    }

                                    if (i == 3) {
                                        break;
                                    }
                                }
                            } while(true);

                        char* encrypted = custom_pw->encryption(KEY);

                        cout << "Your encrypted password (KEY:" << KEY << ") is: ";
                        pw->txtOutput(hConsole, 11, true, string(encrypted));

                        files->file_Save(website, encrypted, liste);
                    } else {
                        cout << "Error; Format was not entered correctly. Return to the menu..." << endl;
                    }
                }
            }
                break;
            }
        case 4:
            {
                liste->display();
                break;
            }
        case 5:
            {
                char* ad_pin = "";
                bool break_bool = false;

                if (liste->suche(".W") == -1) {
                    int pin = 0;
                    ostringstream ostr;

                    cout << "Please create a four-digit administrator PIN." << endl;

                    do {
                        pw->txtOutput(hConsole, 2, false, "=> ");
                        cin >> pin;

                        if (cin.fail()) {
                            cout << "Error; PIN must consist of only numbers! Try again." << endl;
                            cin.clear();
                            cin.sync();
                        } else if (pin > 9999 || pin < 1000) {
                            cout << "Error; PIN must consist of exactly four digits. Try again." << endl;
                        }
                    } while(pin > 9999 || pin < 1000);

                    ostr << pin;
                    string pinn = ostr.str();

                    for (int i = 0; i < 4; i++) {
                        ad_pin = pw->appendChar(ad_pin, pinn[i]);
                    }

                    files->file_Save(".W", ad_pin, liste);

                    cout << "Administrator PIN successfully set! Return to the menu..." << endl;
                    break;
                } else {
                    string pin = "";
                    int stelle = liste->suche(".W");
                    ad_pin = liste->getIndexPassword(stelle);

                    cin.ignore();
                    cout << "Please enter your administrator PIN." << endl;

                    do {
                        pw->txtOutput(hConsole, 2, false, "=> ");
                        cin >> pin;

                        if (pin.size() != 4) {
                            cout << "Error; PIN must be four digits. Try again." << endl;
                        } else if (pin != ad_pin) {
                            cout << "Error; Incorrect PIN entered. Return to menu..." << endl;
                            break_bool = true;
                        }
                    } while(pin.size() != 4);

                    if (break_bool) {
                        break;
                    } else {
                        cin.ignore();
                        cout << "Enter the name of the website whose password you want to delete." << endl;

                        do {
                            pw->txtOutput(hConsole, 2, false, "=> ");
                            getline(cin, website);

                            if (website.size() < 3) {
                                cout << "Error; Website name is too short. Try again." << endl;
                            }
                        } while(website.size() < 3);

                        if (liste->suche(website) == -1) {
                            cout << "Error; Website could not be found! Return to menu..." << endl;
                        } else {
                            liste->loeschen(liste->suche(website), files->getFILE_PATH());
                        }

                        website.clear();
                        break;
                    }
                }
            }
        case 6:
            {
                //return 0;
                exit(0);
            }
        }
    }
    return 1;
}

void toClipboard(HWND hwnd, const string &s) {
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);

	if (!hg) {
		CloseClipboard();
		return;
	}

	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}
