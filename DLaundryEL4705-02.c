#include <assert.h>             // Assertion for truth testing
#include <ctype.h>              // Characters typing methods
#include <conio.h>
#include <errno.h>              // Error handling
#include <dirent.h>             // Working with directories and files
#include <fenv.h>               // File environment handling
#include <float.h>              // Float conversion (more spesific)
#include <limits.h>             // Limitations per data types
#include <math.h>               // Mathematical functions
#include <stdbool.h>            // Standard boolean values handling
#include <stddef.h>             // Standard definitions for certain types
#include <stdint.h>             // Standard integers handling (more spesific)
#include <stdio.h>              // Standard stream handling
#include <stdlib.h>             // Standard library (more spesific)
#include <signal.h>             // Signal handling for future better runtime experience
#include <string.h>             // String manipulation and handling
#include <time.h>               // Time conversion
#include <uchar.h>              // Character conversion (U type conversion)
#include <unistd.h>             // Giving POSIX syntaxes operating system API
#include <wchar.h>              // Wide character conversion (W type conversion)
#include <wctype.h>             // Wide character typing method (String type conversion)
#include <windows.h>

/*
DEFINE::BUFFERSIZE
Usage:  Used for setting a certain spesific buffer for
        spesific variables that might have to work with
        more than just a basic variables (pointers,
        structs, and more).
*/
#define BUFSIZE07   128         // 2^7  buffer size (min. defined)
#define BUFSIZE08   256         // 2^8  buffer size
#define BUFSIZE09   512         // 2^9  buffer size
#define BUFSIZE10   1024        // 2^10 buffer size
#define BUFSIZE11   2048        // 2^11 buffer size
#define BUFSIZE12   4096        // 2^12 buffer size
#define BUFSIZE13   8192        // 2^13 buffer size
#define BUFSIZE14   16384       // 2^14 buffer size
#define BUFSIZE15   32768       // 2^15 buffer size
#define BUFSIZE16   65536       // 2^16 buffer size (max. defined)

/*
DEFINE::APPLANGUAGE
Usage:  Determining the whole application language that
        mostly the user have to interact with. Given two
        languages registered on the system, that is ENG
        for (English) and IND for (Indonesian).
*/
#define USER  true
#define ADMIN false

/*
DEFINE::ARROWKEYWORD
Usage:  For more safe-choice input session, so the user
        can't make any rousy inputs that can interrupt
        the whole core of the app functionality by some
        unexpected errors or bugs.
*/
#define KEY_UP      72
#define KEY_DOWN    80
#define KEY_RIGHT   77
#define KEY_LEFT    75
#define KEY_ENTER   '\r'

/*
DEFINE::DEFINITIVEHISTOGRAM
Usage:  Used for generating a histogram from (y -> x)
        because of the exhaustive printing if done in
        (x -> y) format.
*/
#define SQUARE_BAR "\u2B1C"

/*
DEFINE::ANSICOLORFONTMODE
Usage:  Creating a spesific colored font to highlight the
        ARROWKEYWORD defining session for helping the user
        to know spesifically the choice they're on while
        in the restricted input mode.
*/
#define ANSI_COLOR_RESET           "\x1b[0;0m"
#define ANSI_COLOR_DARKGRAY        "\x1b[0;30m"
#define ANSI_COLOR_RED             "\x1b[0;38;5;196m"
#define ANSI_COLOR_GREEN           "\x1b[0;38;5;82m"
#define ANSI_COLOR_YELLOW          "\x1b[0;38;5;220m"
#define ANSI_COLOR_BLUE            "\x1b[0;38;5;33m"
#define ANSI_COLOR_MAGENTA         "\x1b[0;38;5;207m"
#define ANSI_COLOR_PURPLE          "\x1b[0;38;5;93m"
#define ANSI_COLOR_CYAN            "\x1b[0;38;5;81m"
#define ANSI_COLOR_PINK            "\x1b[0;38;5;206m"
#define ANSI_COLOR_ORANGE          "\x1b[0;38;5;208m"
#define ANSI_COLOR_WHITE           "\x1b[0;37m"
#define ANSI_COLOR_LIGHTRESET      "\x1b[1;0m"
#define ANSI_COLOR_LIGHTGRAY       "\x1b[1;30m"
#define ANSI_COLOR_LIGHTRED        "\x1b[1;38;5;196m"
#define ANSI_COLOR_LIGHTGREEN      "\x1b[1;38;5;82m"
#define ANSI_COLOR_LIGHTYELLOW     "\x1b[1;38;5;220m"
#define ANSI_COLOR_LIGHTBLUE       "\x1b[1;38;5;33m"
#define ANSI_COLOR_LIGHTMAGENTA    "\x1b[1;38;5;207m"
#define ANSI_COLOR_LIGHTPURPLE     "\x1b[1;38;5;93m"
#define ANSI_COLOR_LIGHTCYAN       "\x1b[1;38;5;81m"
#define ANSI_COLOR_LIGHTWHITE      "\x1b[1;37m"
#define ANSI_COLOR_LIGHTORANGE     "\x1b[1;38;5;208m"
#define ANSI_COLOR_LIGHTPINK       "\x1b[1;38;5;206m"
#define ANSI_STYLE_BOLD            "\x1b[1m"
#define ANSI_STYLE_FAINT           "\x1b[2m"
#define ANSI_STYLE_ITALIC          "\x1b[3m"
#define ANSI_STYLE_UNDERLINE       "\x1b[4m"
#define ANSI_STYLE_BLINK           "\x1b[5m"
#define ANSI_STYLE_NEGATIVE        "\x1b[7m"
#define ANSI_STYLE_CROSSED         "\x1b[9m"

/* COLOR HIGHLIGHTING FOR MAIN MENU ONLY */
#define BRIGHTGREEN154             "\x1b[0;38;5;154m"
#define BRIGHTGREEN155             "\x1b[0;38;5;155m"
#define BRIGHTGREEN156             "\x1b[0;38;5;156m"
#define BRIGHTBLUE157              "\x1b[0;38;5;157m"
#define BRIGHTBLUE158              "\x1b[0;38;5;158m"
#define BRIGHTBLUE159              "\x1b[0;38;5;159m"

#define BRIGHTRED216               "\x1b[0;38;5;216m"
#define BRIGHTMAGENTA217           "\x1b[0;38;5;217m"
#define BRIGHTPURPLE218            "\x1b[0;38;5;218m"
#define BRIGHTPINK219              "\x1b[0;38;5;219m"

#define BRIGHTRED208               "\x1b[0;38;5;208m"
#define BRIGHTRED209               "\x1b[0;38;5;209m"
#define BRIGHTMAGENTA210           "\x1b[0;38;5;210m"
#define BRIGHTMAGENTA211           "\x1b[0;38;5;211m"
#define BRIGHTPURPLE212            "\x1b[0;38;5;212m"
#define BRIGHTPURPLE213            "\x1b[0;38;5;213m"

// ClearScreen() method, works for both Windows and UNIX.
void ClearScreen(void) {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
    #error "ERROR: Unsupported platform for performing clear screen!"
#endif
}

char SignedInAccountFullName[BUFSIZE10], SignedInAccountUserName[BUFSIZE07];
bool ApplicationInLoggedIn = false, FirstRuntimeExecution = true;

struct UserProfileAccount {
    char FirstName[BUFSIZE07], LastName[BUFSIZE07];
    char Email[BUFSIZE07], Username[BUFSIZE07], Password[BUFSIZE07], PasswordUI[BUFSIZE07];
    char Birthday[BUFSIZE07], PhoneNumber[BUFSIZE07], Sex[BUFSIZE07];
} UserProfileAccounts;

struct AdminProfileAccount {
    char FirstName[BUFSIZE07], LastName[BUFSIZE07];
    char Email[BUFSIZE07], Username[BUFSIZE07], Password[BUFSIZE07], PasswordUI[BUFSIZE07];
    char Birthday[BUFSIZE07], PhoneNumber[BUFSIZE07], Sex[BUFSIZE07];
    char AdminCode[BUFSIZE07];
} AdminProfileAccounts;

struct SaveFilesTxtName {
    char FileNames[BUFSIZE07];
} SaveFilesTxtName[BUFSIZE10];
signed int FilePathNameTraversalCounter = 0, CountSavedFiles = 0;
signed int Accounts = 0, SignedInAccountNo = 0, CountLoggedInAccounts = 0;

int  main(void);
void AccountRegistrationMenu(bool);
void AccountLoginMenu(bool);
void HomePageMenu(bool);

void ServicesNo01(signed int);
void ServicesNo02(signed int);
void ServicesNo03(signed int);
void OtherServices(void);

void EncryptTxtFile(const char*, const char*, int, bool);
void DecryptTxtFile(const char*, bool, int, char ReadDecryptedKeyString[BUFSIZE16]);
void MatchSaveFileTxt(const char*, const char*);
int  FindOccurences(const char*, char);
char *TrimWhiteSpaces(char*);
char *StringUppercase(char*);

char *TrimWhiteSpaces(char* SourceString) {
    char *EndString;

    while (isspace((unsigned char) *SourceString)) SourceString++;  // Trim leading space
    if (*SourceString == 0) return SourceString;                    // All spaces?
    EndString = SourceString + strlen(SourceString) - 1;            // Trim trailing space
    while (EndString > SourceString && isspace((unsigned char) *EndString)) EndString--;

    EndString[1] = '\0'; // Write new null terminator character
    return SourceString;
}

char *ReadAndPrintLine(const char* SourceTextFile, intmax_t Line) {
    FILE *FSource = fopen(SourceTextFile, "r");
    char Buffer[BUFSIZE10], *ReturnBuffer = malloc(BUFSIZE10);
    intmax_t Lines = 0;
    
    do {
        if (++Lines == Line) {
            fgets(Buffer, BUFSIZE10, FSource);
            break;
        }
    } while((fscanf(FSource, "%*[^\n]"), fscanf(FSource, "%*c")) != EOF);
    if (Lines == Line) { strcpy(ReturnBuffer, Buffer); fclose(FSource); return ReturnBuffer; }
    fclose(FSource); ReturnBuffer = "None"; return ReturnBuffer;
}

void OverWriteStringAtLine(const char* FSourceTxtFile, const char* NewOverWriteString, const int EncryptionKey, signed int AtSpesificLine) {
	FILE *FSource, *FDestination, *FCopyAndDecrypting, *FTempDestination;
	int AtLine = AtSpesificLine, LineControl = 0, BufLen = 0;
	char BUFFER[BUFSIZE16], NewlyString[BUFSIZE16], FileName[BUFSIZE16];      
	char OverWriteStringLine[BUFSIZE16], FTempDestinationTxtFile[BUFSIZE16] = "TempDestination.txt", DeleteTempDestinationTxtFile[BUFSIZE16];
	
	FCopyAndDecrypting = fopen(FSourceTxtFile, "r");
	FTempDestination   = fopen("FTempDestination.txt", "w");
	while (fgets(BUFFER, sizeof(BUFFER), FCopyAndDecrypting) != 0) {
		BufLen = strlen(BUFFER);
		for (int i = 0; i < BufLen; i++) BUFFER[i] += EncryptionKey;
		fputs(BUFFER, FTempDestination);
	} fclose(FCopyAndDecrypting); fclose(FTempDestination);

	strncpy(FileName, FSourceTxtFile, BUFSIZE16);
	FSource      = fopen("FTempDestination.txt", "r");
	FDestination = fopen(FTempDestinationTxtFile, "w");
	if (!FSource)      { }
	if (!FDestination) { }

	strncpy(OverWriteStringLine, NewOverWriteString, BUFSIZE16);
	strcat(OverWriteStringLine, "\n");

	while (!feof(FSource)) {
		strcpy(NewlyString, "\0");
		fgets(NewlyString, BUFSIZE16, FSource);

		if (!feof(FSource))  {
			LineControl++;
			if (LineControl != AtLine) { fputs(NewlyString, FDestination); }
			else { fputs(OverWriteStringLine, FDestination); }
		}
	} fclose(FSource);
	fclose(FDestination);
	remove(FileName); rename(FTempDestinationTxtFile, FileName);

    strcpy(DeleteTempDestinationTxtFile, "del ");
    strcat(DeleteTempDestinationTxtFile, "FTempDestination.txt");
    system(DeleteTempDestinationTxtFile);
}

char *StringUppercase(char* SourceString) {
    for (int i = 0; SourceString[i] != '\0'; i++) {
        if (SourceString[i] >= 'a' && SourceString[i] <= 'z') { SourceString[i] -= 32; }
    } return SourceString;
}

int FindOccurences(const char* SourceString, char SearchedOccurence) {
    int CountOccurences;
    for (int i = 0; (long long unsigned int)i < strlen(SourceString) - 1; i++) {
        if (SourceString[i] == SearchedOccurence) CountOccurences++;
    } return CountOccurences;
}

/* Abbreviation of "Encrypt Text File" is one of the CORE FEATURES here in this application,
and the return type function is `void()`, and requires the program to accept:
`>>>` FOUR (4) arguments, accordingly as explained below.

`> const char *SourceTextFile`: A source text file that needs to be the source before being encrypted.
`> const char *DestinationTextFile`: A destination text file that needs to be the place of the after-encrypted.
`> int EncryptionKey`: A MUST required encryption key in order the text file to be encrypted. The code is spesific, and MUST be set in the program code before runtime, or included in the `**argv` parameter at command line before runtime. The encryption key HAS TO BE THE SAME for the decryption key, because one different in a single number will resulted in a non-correct encryption/decryption method.
`> bool SourceTextFileDeletion`: Mode for deleting the source text file right after the encryption, so the copy of the data will not get leaked if the source that's not get encrypted is stil intact on the folder.

`[Format: 4th argument] <TRUE> || <FALSE>`
*/
void EncryptTxtFile(const char* SourceTextFile, const char* DestinationTextFile, int EncryptionKey, bool SourceTextFileDeletion) {
    FILE *FSource, *FDestination;
    int BufLen;
    char BUFFER[BUFSIZE16], DeleteSourceTxtFile[128];

    FSource         = fopen(SourceTextFile, "r");
    FDestination    = fopen(DestinationTextFile, "w");
    
    while (fgets(BUFFER, sizeof(BUFFER), FSource) != 0) {
        BufLen = strlen(BUFFER);
        for (int i = 0; i < BufLen; i++) BUFFER[i] -= EncryptionKey;
        fputs(BUFFER, FDestination);
    }
    fclose(FSource); fclose(FDestination);

    if (SourceTextFileDeletion) {
        strcpy(DeleteSourceTxtFile, "del ");
        strcat(DeleteSourceTxtFile, SourceTextFile);
        system(DeleteSourceTxtFile);
    } else NULL;
}

/* Abbreviation of "Decrypt Text File" is one of the CORE FEATURES here in this application,
and the return type function is `void()`, and requires the program to accept:
`>>>` FOUR (4) arguments, accordingly as explained below.

`> const char *DestinationTextFile`: A destination text file that needs to be decrypted.
`> bool ReadDecryptedFile`: Mode for reading the whole contents of the decrypted file.
`> int DecryptionKey`: A MUST required decryption key in order the text file to be decrypted. The code is spesific, and MUST be set in the program code before runtime, or included in the `**argv` parameter at command line before runtime. The encryption key HAS TO BE THE SAME for the decryption key, because one different in a single number will resulted in a non-correct encryption/decryption method.
`> char ReadDecryptedKeyString[BUFSIZE16]`: Use to search and find a certain key of strings in the decrypted text file, and this argumen have a spesific format and delimiters, and this argument can be used to find more than one key strings, but in the same time can be only one text file at a time, and that's the file you chose to decrypted when assigning it to this argument. This argument has `65,536` or `2^16` buffer size, meaning you can input a total of `65,536` characters inside as a string. 

`[Format: 2nd argument] <TRUE> || <FALSE>`
`[Format: 4th argument] <TEXTFILE.txt> > <STRINGKEY8LIST>`
*/
void DecryptTxtFile(const char* DestinationTextFile, bool ReadDecryptedFile, int DecryptionKey, char ReadDecryptedKeyString[BUFSIZE16]) {
    FILE *FDestination, *FTempDestination;
    int BufLen, Ptr = 0, KeyTracker = 0, LineTracker = 0, FTDPos = 0;
    char C, BUFFER[BUFSIZE16], DeleteTempDestinationTxtFile[128], TxtFileName[128];
    char *SourceTextFileName, *SourceKeyStringValue, *SelectedKeyString;
    char *SourceKeyStringValues[BUFSIZE16], FTDestination[BUFSIZE10][BUFSIZE10];

    FDestination = fopen(DestinationTextFile, "r");
    if (ReadDecryptedFile) {
        while (fgets(BUFFER, sizeof(BUFFER), FDestination) != 0) {
            BufLen = strlen(BUFFER);
            for (int i = 0; i < BufLen; i++) BUFFER[i] += DecryptionKey;
            fputs(BUFFER, stdout);
        }
    } fclose(FDestination);

    if (strcmp(ReadDecryptedKeyString, "None") == 0) NULL;
    else {
        FDestination     = fopen(DestinationTextFile, "r");
        FTempDestination = fopen("TempDestination.txt", "w");

        while (fgets(BUFFER, sizeof(BUFFER), FDestination) != 0) {
            BufLen = strlen(BUFFER);
            for (int i = 0; i < BufLen; i++) BUFFER[i] += DecryptionKey;
            fputs(BUFFER, FTempDestination);
        } fclose(FDestination); fclose(FTempDestination);

        strcpy(TxtFileName, ReadDecryptedKeyString);
        strtok_r(TxtFileName, ">", &SelectedKeyString);
        SelectedKeyString = TrimWhiteSpaces(SelectedKeyString);
        SourceKeyStringValue = strtok(SelectedKeyString, ",");
        KeyTracker++;

        while (SourceKeyStringValue != NULL) {
            SourceKeyStringValues[Ptr] = SourceKeyStringValue;
            SourceKeyStringValues[Ptr] = TrimWhiteSpaces(SourceKeyStringValues[Ptr]);
            SourceKeyStringValue = strtok(NULL, ",");
            Ptr++; KeyTracker++;
        } SourceTextFileName = TrimWhiteSpaces(TxtFileName);
        
        if (strcmp(SourceTextFileName, DestinationTextFile) == 0) {
            if ((strchr(TxtFileName, ':') == NULL) && (strchr(SelectedKeyString, ':') == NULL)) {
                int FTDIndex = 0, SKSVIndex = 0;

                FDestination = fopen("TempDestination.txt", "r");
                for (C = getc(FDestination); C != EOF; C = getc(FDestination))
                    if (C == '\n') LineTracker++;
                fclose(FDestination);

                FDestination = fopen("TempDestination.txt", "r");
                while(fgets(FTDestination[FTDPos], BUFSIZE10, FDestination) != NULL) {
                    if (FTDPos < LineTracker)
                        FTDestination[FTDPos][strlen(FTDestination[FTDPos]) - 1] = '\0';
                    FTDPos++;
                } fclose(FDestination);

                while (FTDIndex <= LineTracker) {
                    while (SKSVIndex <= KeyTracker - 2) {
                        if (strstr(FTDestination[FTDIndex], SourceKeyStringValues[SKSVIndex]) != NULL) {
                            printf("%s\n", FTDestination[FTDIndex]); break;
                        } else if (strstr(FTDestination[FTDIndex], SourceKeyStringValues[SKSVIndex]) == NULL)
                            SKSVIndex++;
                    } FTDIndex++; SKSVIndex = 0;
                }
                strcpy(DeleteTempDestinationTxtFile, "del ");
                strcat(DeleteTempDestinationTxtFile, "TempDestination.txt");
                system(DeleteTempDestinationTxtFile);
            }
        } else {
            strcpy(DeleteTempDestinationTxtFile, "del ");
            strcat(DeleteTempDestinationTxtFile, "TempDestination.txt");
            system(DeleteTempDestinationTxtFile);
        }
    }
}

void MatchSaveFileTxt(const char *DirectoryPath, const char *FullFileNameOrSubstringFileName) {
    struct dirent *DIRFiles;
    char SaveFileTxtName[BUFSIZE07];
    DIR *DIRPath = opendir(DirectoryPath);
    
    if (DIRPath == NULL) { NULL; }
    while ((DIRFiles = readdir(DIRPath)) != NULL) {
        if (strstr(DIRFiles -> d_name, FullFileNameOrSubstringFileName)) {
            snprintf(SaveFileTxtName, BUFSIZE07, "%s", DIRFiles -> d_name);
            strcpy(SaveFilesTxtName[FilePathNameTraversalCounter].FileNames, SaveFileTxtName);
            FilePathNameTraversalCounter++;
        }
    } closedir(DIRPath);
}

void AccountRegistrationMenu(bool UserMode) {
    FILE *RegisteredUsers, *RegisteredAdmins;

    ClearScreen(); fflush(stdin);
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Registration ═══════════════════════════"ANSI_COLOR_RESET);
    
    puts("");
    puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!\n\t\t   Silakan melakukan registrasi terlebih dahulu..."ANSI_COLOR_RESET);
    
    puts("");
    if (UserMode == USER) {
        RegisteredUsers = fopen("RegisteredUsers.dat", "ab");

        printf(BRIGHTBLUE157 ANSI_STYLE_ITALIC"(First Name)   "ANSI_COLOR_RESET BRIGHTBLUE157"Nama Depan:    "); fgets(UserProfileAccounts.FirstName, BUFSIZE07, stdin);
        printf(BRIGHTBLUE157 ANSI_STYLE_ITALIC"(Last Name)    "ANSI_COLOR_RESET BRIGHTBLUE157"Nama Belakang: "); fgets(UserProfileAccounts.LastName, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Email)        "ANSI_COLOR_RESET BRIGHTBLUE158"Email:         "); fgets(UserProfileAccounts.Email, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Username)     "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: "); fgets(UserProfileAccounts.Username, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Password)     "ANSI_COLOR_RESET BRIGHTBLUE158"Kata Sandi:    "); fgets(UserProfileAccounts.Password, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Birthday)     "ANSI_COLOR_RESET BRIGHTBLUE159"Tanggal Lahir: "); fgets(UserProfileAccounts.Birthday, BUFSIZE07, stdin);
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Phone Number) "ANSI_COLOR_RESET BRIGHTBLUE159"No. HP:        "); fgets(UserProfileAccounts.PhoneNumber, BUFSIZE07, stdin);
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Sex)          "ANSI_COLOR_RESET BRIGHTBLUE159"Jenis Kelamin: "); fgets(UserProfileAccounts.Sex, BUFSIZE07, stdin);

        UserProfileAccounts.FirstName[strlen(UserProfileAccounts.FirstName) - 1]     = '\0';
        UserProfileAccounts.LastName[strlen(UserProfileAccounts.LastName) - 1]       = '\0';
        UserProfileAccounts.Email[strlen(UserProfileAccounts.Email) - 1]             = '\0';
        UserProfileAccounts.Username[strlen(UserProfileAccounts.Username) - 1]       = '\0';
        UserProfileAccounts.Password[strlen(UserProfileAccounts.Password) - 1]       = '\0';
        UserProfileAccounts.Birthday[strlen(UserProfileAccounts.Birthday) - 1]       = '\0';
        UserProfileAccounts.PhoneNumber[strlen(UserProfileAccounts.PhoneNumber) - 1] = '\0';
        UserProfileAccounts.Sex[strlen(UserProfileAccounts.Sex) - 1]                 = '\0';

        puts(ANSI_COLOR_RESET"");
        fwrite(&UserProfileAccounts, sizeof(UserProfileAccounts), 1, RegisteredUsers);
        fclose(RegisteredUsers);
        AccountLoginMenu(USER);

        // RegisteredUsers = fopen("RegisteredUsers.dat", "rb");
        // while (fread(&UserProfileAccounts, sizeof(UserProfileAccounts), 1, RegisteredUsers) == 1) {
        //     printf("%s\n", UserProfileAccounts.FirstName);
        //     printf("%s\n", UserProfileAccounts.LastName);
        //     printf("%s\n", UserProfileAccounts.Email);
        //     printf("%s\n", UserProfileAccounts.Username);
        //     printf("%s\n", UserProfileAccounts.Password);
        //     printf("%s\n", UserProfileAccounts.Birthday);
        //     printf("%s\n", UserProfileAccounts.PhoneNumber);
        //     printf("%s\n", UserProfileAccounts.Sex);
        //     puts("");
        // } fclose(RegisteredUsers);
        
    } else {
        RegisteredAdmins = fopen("RegisteredAdmins.dat", "ab");

        printf(BRIGHTBLUE157 ANSI_STYLE_ITALIC"(First Name)   "ANSI_COLOR_RESET BRIGHTBLUE157"Nama Depan:    "); fgets(AdminProfileAccounts.FirstName, BUFSIZE07, stdin);
        printf(BRIGHTBLUE157 ANSI_STYLE_ITALIC"(Last Name)    "ANSI_COLOR_RESET BRIGHTBLUE157"Nama Belakang: "); fgets(AdminProfileAccounts.LastName, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Email)        "ANSI_COLOR_RESET BRIGHTBLUE158"Email:         "); fgets(AdminProfileAccounts.Email, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Username)     "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: "); fgets(AdminProfileAccounts.Username, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Password)     "ANSI_COLOR_RESET BRIGHTBLUE158"Kata Sandi:    "); fgets(AdminProfileAccounts.Password, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Birthday)     "ANSI_COLOR_RESET BRIGHTBLUE159"Tanggal Lahir: "); fgets(AdminProfileAccounts.Birthday, BUFSIZE07, stdin);
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Phone Number) "ANSI_COLOR_RESET BRIGHTBLUE159"No. HP:        "); fgets(AdminProfileAccounts.PhoneNumber, BUFSIZE07, stdin);
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Sex)          "ANSI_COLOR_RESET BRIGHTBLUE159"Jenis Kelamin: "); fgets(AdminProfileAccounts.Sex, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Admin Code)   "ANSI_COLOR_RESET BRIGHTBLUE159"Kode Admin:    "); fgets(AdminProfileAccounts.AdminCode, BUFSIZE07, stdin);

        AdminProfileAccounts.FirstName[strlen(AdminProfileAccounts.FirstName) - 1]     = '\0';
        AdminProfileAccounts.LastName[strlen(AdminProfileAccounts.LastName) - 1]       = '\0';
        AdminProfileAccounts.Email[strlen(AdminProfileAccounts.Email) - 1]             = '\0';
        AdminProfileAccounts.Username[strlen(AdminProfileAccounts.Username) - 1]       = '\0';
        AdminProfileAccounts.Password[strlen(AdminProfileAccounts.Password) - 1]       = '\0';
        AdminProfileAccounts.Birthday[strlen(AdminProfileAccounts.Birthday) - 1]       = '\0';
        AdminProfileAccounts.PhoneNumber[strlen(AdminProfileAccounts.PhoneNumber) - 1] = '\0';
        AdminProfileAccounts.Sex[strlen(AdminProfileAccounts.Sex) - 1]                 = '\0';
        AdminProfileAccounts.AdminCode[strlen(AdminProfileAccounts.AdminCode) - 1]                 = '\0';

        puts(ANSI_COLOR_RESET"");
        fwrite(&AdminProfileAccounts, sizeof(AdminProfileAccounts), 1, RegisteredAdmins);
        fclose(RegisteredAdmins);
        AccountLoginMenu(ADMIN);

        // RegisteredAdmins = fopen("RegisteredAdmins.dat", "rb");
        // while (fread(&AdminProfileAccounts, sizeof(AdminProfileAccounts), 1, RegisteredAdmins) == 1) {
        //     printf("%s\n", AdminProfileAccounts.FirstName);
        //     printf("%s\n", AdminProfileAccounts.LastName);
        //     printf("%s\n", AdminProfileAccounts.Email);
        //     printf("%s\n", AdminProfileAccounts.Username);
        //     printf("%s\n", AdminProfileAccounts.Password);
        //     printf("%s\n", AdminProfileAccounts.Birthday);
        //     printf("%s\n", AdminProfileAccounts.PhoneNumber);
        //     printf("%s\n", AdminProfileAccounts.Sex);
        //     printf("%s\n", AdminProfileAccounts.AdminCode);
        //     puts("");
        // } fclose(RegisteredAdmins);
    }
}

void AccountLoginMenu(bool UserMode) {
    FILE *RegisteredUsers, *RegisteredAdmins, *RegisteredUserSaveFile, *RegisteredAdminSaveFile;
    char Email[BUFSIZE07], Username[BUFSIZE07], Password[BUFSIZE07], AdminCode[BUFSIZE07];
    char GeneratingSaveFile[BUFSIZE07];

    if (!ApplicationInLoggedIn) { NULL; }
    else { main(); }

    ClearScreen(); fflush(stdin);
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156"═════════════════════════════ Starting In :: Logging In ════════════════════════════"ANSI_COLOR_RESET);
    
    puts("");
    puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!\n     Silakan " ANSI_STYLE_UNDERLINE"PILIH dan MASUKKAN"ANSI_COLOR_RESET BRIGHTBLUE158" akun untuk " ANSI_STYLE_ITALIC"(signing in/login) "ANSI_COLOR_RESET BRIGHTBLUE158"terlebih dahulu..."ANSI_COLOR_RESET);

    if (UserMode == USER) {
        puts("");
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Email)        "ANSI_COLOR_RESET BRIGHTBLUE158"Email:         "); fgets(Email, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Username)     "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: "); fgets(Username, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Password)     "ANSI_COLOR_RESET BRIGHTBLUE158"Kata Sandi:    "); fgets(Password, BUFSIZE07, stdin);

        Email[strlen(Email) - 1]       = '\0';
        Username[strlen(Username) - 1] = '\0';
        Password[strlen(Password) - 1] = '\0';

        RegisteredUsers = fopen("RegisteredUsers.dat", "rb");
        while (fread(&UserProfileAccounts, sizeof(UserProfileAccounts), 1, RegisteredUsers) == 1) {
            if (strncmp(UserProfileAccounts.Email, Email, BUFSIZE07) == 0 && strncmp(UserProfileAccounts.Username, Username, BUFSIZE07) == 0 && strncmp(UserProfileAccounts.Password, Password, BUFSIZE07) == 0) {
                ApplicationInLoggedIn = true;
                strncpy(SignedInAccountFullName, UserProfileAccounts.FirstName, BUFSIZE09); strncat(SignedInAccountFullName, UserProfileAccounts.LastName, BUFSIZE09);
                strncpy(SignedInAccountUserName, UserProfileAccounts.Username, BUFSIZE07);
                strcpy(GeneratingSaveFile, SignedInAccountUserName); strcat(GeneratingSaveFile, "-USER-SaveFile.dat");

                RegisteredUserSaveFile = fopen(GeneratingSaveFile, "wb");
                fwrite(&UserProfileAccounts, sizeof(UserProfileAccounts), 1, RegisteredUserSaveFile);
                
                ClearScreen(); fflush(stdin);
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"═════════════════════════════ Starting In :: Logging In ════════════════════════════"ANSI_COLOR_RESET);
                
                puts("");
                printf(BRIGHTBLUE159"\t\tSelamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE159", pengguna atas nama:\n\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Full Name) "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Lengkap:  " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (User Name) "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName);
                
                getchar();
                fclose(RegisteredUserSaveFile); fclose(RegisteredUsers);
                HomePageMenu(USER);
            }
        } fclose(RegisteredUsers);
        AccountLoginMenu(USER);

    } else {
        puts("");
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Email)        "ANSI_COLOR_RESET BRIGHTBLUE158"Email:         "); fgets(Email, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Username)     "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: "); fgets(Username, BUFSIZE07, stdin);
        printf(BRIGHTBLUE158 ANSI_STYLE_ITALIC"(Password)     "ANSI_COLOR_RESET BRIGHTBLUE158"Kata Sandi:    "); fgets(Password, BUFSIZE07, stdin);

        puts("");
        printf(BRIGHTBLUE159 ANSI_STYLE_ITALIC"(Admin Code)   "ANSI_COLOR_RESET BRIGHTBLUE159"Kode Admin:    "); fgets(AdminCode, BUFSIZE07, stdin);

        Email[strlen(Email) - 1]         = '\0';
        Username[strlen(Username) - 1]   = '\0';
        Password[strlen(Password) - 1]   = '\0';
        AdminCode[strlen(AdminCode) - 1] = '\0';

        RegisteredAdmins = fopen("RegisteredAdmins.dat", "rb");
        while (fread(&AdminProfileAccounts, sizeof(AdminProfileAccounts), 1, RegisteredAdmins) == 1) {
            if (strncmp(AdminProfileAccounts.Email, Email, BUFSIZE07) == 0 && strncmp(AdminProfileAccounts.Username, Username, BUFSIZE07) == 0 && strncmp(AdminProfileAccounts.Password, Password, BUFSIZE07) == 0 && strncmp(AdminProfileAccounts.AdminCode, AdminCode, BUFSIZE07) == 0) {
                ApplicationInLoggedIn = true;
                strncpy(SignedInAccountFullName, AdminProfileAccounts.FirstName, BUFSIZE09); strncat(SignedInAccountFullName, AdminProfileAccounts.LastName, BUFSIZE09);
                strncpy(SignedInAccountUserName, AdminProfileAccounts.Username, BUFSIZE07);
                strcpy(GeneratingSaveFile, SignedInAccountUserName); strcat(GeneratingSaveFile, "-ADMIN-SaveFile.dat");

                RegisteredAdminSaveFile = fopen(GeneratingSaveFile, "wb");
                fwrite(&AdminProfileAccounts, sizeof(AdminProfileAccounts), 1, RegisteredAdminSaveFile);
                
                ClearScreen(); fflush(stdin);
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"═════════════════════════════ Starting In :: Logging In ════════════════════════════"ANSI_COLOR_RESET);
                
                puts("");
                printf(BRIGHTBLUE159"\t\tSelamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE159", operator atas nama:\n\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Full Name)  "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Lengkap:  " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (User Name)  "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Admin Code) "ANSI_COLOR_RESET BRIGHTBLUE158"Kode Admin:    " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName, AdminProfileAccounts.AdminCode);
                
                getchar();
                fclose(RegisteredAdminSaveFile); fclose(RegisteredAdmins);
                HomePageMenu(ADMIN);
            }
        } fclose(RegisteredAdmins);
        AccountLoginMenu(ADMIN);
    }
}

void HomePageMenu(bool UserMode) {
    int ValidIntInput;
    signed int ServiceOption;

    if (UserMode == USER) {
        do {
            ClearScreen();
            puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN155"═════════════════════════════ In Progress :: Dashboard ═════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"══════════════════════════════════ Home Page Menu ══════════════════════════════════"ANSI_COLOR_RESET);

            printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET, SignedInAccountUserName);

            puts("");
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"═════════════════════════════ CUCI KILOAN (per. kg) ════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218"[1] 💐 Reguler ➡ 48 Jam Kerja (maks. 72)         ⏩ Rp6.000,00/kg                😊"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218"[2] 🍀 Express ➡ 24 Jam Kerja (maks. 36)         ⏩ Rp8.000,00/kg                😍"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218"[3] 🌠 Instant ➡ 12 Jam Kerja (maks. 24)         ⏩ Rp10.000,00/kg               🤩"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159 ANSI_STYLE_BOLD"════════════════════════════ RUMAH TANGGA (optional) ═══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159"[4] 🌷 Sprei/Selimut/Sarung Guling/Sarung Bantal ⏩ Rp15.000,00/jumlah           🤗"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159"[5] 💛 Bed Cover (Ukuran: KECIL)                 ⏩ Rp10.000,00/jumlah           🤗"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159"[6] 💚 Bed Cover (Ukuran: SEDANG)                ⏩ Rp13.000,00/jumlah           🤗"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159"[7] 💙 Bed Cover (Ukuran: BESAR)                 ⏩ Rp16.000,00/jumlah           🤗"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"═════════════════════════════ TAMBAHAN* (optional) ═════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"[8] 🎧 Sepatu (Jenis dan Ukuran: BEBAS)          ⏩ Rp15.000,00+/jumlah (merk)+  🥰"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"[9] 💎 Tas    (Jenis dan Ukuran: BEBAS)          ⏩ Rp15.000,00+/jumlah (merk)+  🥰"ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTRED216"[99] ・‥…━━━★ Pilihan Lainnya ☆.。.:*            ⏩ (Top Up Saldo, dll)          😆"ANSI_COLOR_RESET);
            puts(BRIGHTPINK219"\nCatatan:\n*TAMBAHAN ➡ (biaya dapat bervariasi, tergantung merk barang)");
            
            printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &ServiceOption); fflush(stdin);
        } while (ValidIntInput == 0);

        switch (ServiceOption) {
            case 1: ServicesNo01(1); break;
            case 2: ServicesNo01(2); break;
            case 3: ServicesNo01(3); break;
            case 4: ServicesNo02(4); break;
            case 5: ServicesNo02(5); break;
            case 6: ServicesNo02(6); break;
            case 7: ServicesNo02(7); break;
            case 8: ServicesNo03(8); break;
            case 9: ServicesNo03(9); break;
            case 99: OtherServices(); break;
            default: HomePageMenu(USER); break;
        }
    }
}

void ServicesNo01(void) {

}

void ServicesNo02(void) {

}

void ServicesNo03(void) {

}

void OtherServices(void) {

}

int main(void) {
    SetConsoleOutputCP(65001);
    int ValidIntInput = 0;
    signed int LoginOption, LoginMode;

    if (FirstRuntimeExecution) {
        MatchSaveFileTxt("./", "-SaveFile");
        for (int i = 0; i < BUFSIZE10; i++) {
            puts(SaveFilesTxtName[i].FileNames);
            if (strlen(SaveFilesTxtName[i].FileNames) != 0) CountLoggedInAccounts++;
            else break;
        } FirstRuntimeExecution = false;
    }

    if (CountLoggedInAccounts >= 2) {
        ClearScreen();
        puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Landing Page ═══════════════════════════"ANSI_COLOR_RESET);
        
        puts("");
        puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!"ANSI_COLOR_RESET);
        printf("%d Accounts.\n", CountLoggedInAccounts);
        getchar();

    } else if (CountLoggedInAccounts == 1) {
        ClearScreen();
        puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Landing Page ═══════════════════════════"ANSI_COLOR_RESET);
        
        puts("");
        puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!"ANSI_COLOR_RESET);
        printf("%d Accounts.\n", CountLoggedInAccounts);
        getchar();
    }

    do {
        ClearScreen();
        puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Landing Page ═══════════════════════════"ANSI_COLOR_RESET);
        
        puts("");
        puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!"ANSI_COLOR_RESET);
        puts(BRIGHTPURPLE212"\nSebelum memasuki aplikasi ini lebih lanjut, silakan lanjutkan terlebih dahulu proses"ANSI_COLOR_RESET);
        puts(BRIGHTPURPLE212"langkah awal Anda dengan me-registrasi akun " BRIGHTPURPLE213 ANSI_STYLE_ITALIC ANSI_STYLE_UNDERLINE ANSI_STYLE_BOLD"(login jika sudah punya akun)"ANSI_COLOR_RESET BRIGHTPURPLE212 " dengan\nprofil akun yang kalian miliki.");
        puts(BRIGHTPURPLE218 "  " ANSI_STYLE_BOLD "\n\t\t\t       " ANSI_STYLE_UNDERLINE"REGISTRASI " ANSI_STYLE_ITALIC"(Siging Up)"ANSI_COLOR_RESET BRIGHTPINK219"\n\t\t\t\t      ataupun"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_BOLD "\n\t\t\t\t " ANSI_STYLE_UNDERLINE"LOGIN " ANSI_STYLE_ITALIC"(Signing In)"ANSI_COLOR_RESET);

        puts("");
        puts(BRIGHTPURPLE212"Silakan tentukan pilihan Anda!"ANSI_COLOR_RESET);
        puts(BRIGHTPURPLE218"[0]: Registrasi Akun (Pengguna & Admin)"ANSI_COLOR_RESET);
        puts(BRIGHTBLUE158"[1]: Logging In Akun (Pengguna & Admin)"ANSI_COLOR_RESET);

        puts("");
        printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &LoginOption);
        printf(ANSI_COLOR_RESET""); fflush(stdin);
    } while (ValidIntInput == 0);

    switch (LoginOption) {
        case 0:
            do {
                ClearScreen();
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Landing Page ═══════════════════════════"ANSI_COLOR_RESET);
                
                puts("");
                puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!"ANSI_COLOR_RESET);
                puts(BRIGHTPURPLE212"\nSebelum memasuki aplikasi ini lebih lanjut, silakan lanjutkan terlebih dahulu proses"ANSI_COLOR_RESET);
                puts(BRIGHTPURPLE212"langkah awal Anda dengan me-registrasi akun " BRIGHTPURPLE213 ANSI_STYLE_ITALIC ANSI_STYLE_UNDERLINE ANSI_STYLE_BOLD"(login jika sudah punya akun)"ANSI_COLOR_RESET BRIGHTPURPLE212 " dengan\nprofil akun yang kalian miliki.");
                puts(BRIGHTPURPLE218 "  " ANSI_STYLE_BOLD "\n\t\t\t   >>> " ANSI_STYLE_UNDERLINE"REGISTRASI " ANSI_STYLE_ITALIC"(Siging Up)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" <<< "ANSI_COLOR_RESET BRIGHTPINK219"\n\t\t\t\t      ataupun"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_BOLD "\n\t\t\t\t " ANSI_STYLE_UNDERLINE"LOGIN " ANSI_STYLE_ITALIC"(Signing In)"ANSI_COLOR_RESET);
                
                puts("");
                puts(BRIGHTPURPLE218"Informasi diterima. Apakah Anda ingin me-registrasikan akun pribadi pengguna Anda, ");
                puts("atau akun operator yang berperan sebagai ADMIN dari SKYR D'Laundry?"ANSI_COLOR_RESET);
                puts(BRIGHTBLUE159"[0]: Pengguna (User)"ANSI_COLOR_RESET);
                puts(BRIGHTBLUE159"[1]: Operator (Admin)"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &LoginMode);
                printf(ANSI_COLOR_RESET""); fflush(stdin);
                break;
            } while (ValidIntInput == 0);
            
            switch (LoginMode) {
                case 0:  AccountRegistrationMenu(USER);  break;
                case 1:  AccountRegistrationMenu(ADMIN); break;
                default: main(); break;
            }
        case 1:
            do {
                ClearScreen();
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"════════════════════════════ Starting Up :: Landing Page ═══════════════════════════"ANSI_COLOR_RESET);
                
                puts("");
                puts(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!"ANSI_COLOR_RESET);
                puts(BRIGHTPURPLE212"\nSebelum memasuki aplikasi ini lebih lanjut, silakan lanjutkan terlebih dahulu proses"ANSI_COLOR_RESET);
                puts(BRIGHTPURPLE212"langkah awal Anda dengan me-registrasi akun " BRIGHTPURPLE213 ANSI_STYLE_ITALIC ANSI_STYLE_UNDERLINE ANSI_STYLE_BOLD"(login jika sudah punya akun)"ANSI_COLOR_RESET BRIGHTPURPLE212 " dengan\nprofil akun yang kalian miliki.");
                puts(BRIGHTPURPLE218 "  " ANSI_STYLE_BOLD "\n\t\t\t       " ANSI_STYLE_UNDERLINE"REGISTRASI " ANSI_STYLE_ITALIC"(Siging Up)"ANSI_COLOR_RESET BRIGHTPINK219"\n\t\t\t\t      ataupun"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_BOLD "\n\t\t\t     >>> " ANSI_STYLE_UNDERLINE"LOGIN " ANSI_STYLE_ITALIC"(Signing In)"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_BOLD" <<< "ANSI_COLOR_RESET);
                
                puts("");
                puts(BRIGHTPURPLE218"Informasi diterima. Apakah Anda ingin masuk dengan akun pribadi pengguna Anda, atau");
                puts("dengan akun operator yang berperan sebagai ADMIN dari SKYR D'Laundry?"ANSI_COLOR_RESET);
                puts(BRIGHTBLUE159"[0]: Pengguna (User)"ANSI_COLOR_RESET);
                puts(BRIGHTBLUE159"[1]: Operator (Admin)"ANSI_COLOR_RESET);

                puts("");
                printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &LoginMode);
                printf(ANSI_COLOR_RESET""); fflush(stdin);
                break;
            } while (ValidIntInput == 0);
            
            switch (LoginMode) {
                case 0:  AccountLoginMenu(USER);  break;
                case 1:  AccountLoginMenu(ADMIN); break;
                default: main(); break;
            }
        default: main(); break;
    }
}