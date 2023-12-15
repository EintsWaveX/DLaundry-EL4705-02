#include <assert.h>             // Assertion for truth testing
#include <ctype.h>              // Characters typing methods
#include <conio.h>              // Working on Windows compatibility
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
#include <windows.h>            // Library for Windows specific functions

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

FILE *SignedInAccountSaveFile;
char SignedInAccountFullName[BUFSIZE10], SignedInAccountUserName[BUFSIZE07], SignedInAccountAdminCode[BUFSIZE07];
bool ApplicationInLoggedIn = false, FirstRuntimeExecution = true, VisitedCheckListServiceNo01 = false;

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

struct SKYRDLaundry {
    char ServiceOrderNo[BUFSIZE07];
    signed int Shirt, TShirt, InnerShirt, Socks, Sweater, Jacket, Vest, Mukena;
    signed int Kebaya, PrayerMat, LongPants, ShortPants, InnerPants, Towel, Skirt, HouseDress;
    signed int MuslimClothing, Gloves, GownDress, Handkerchief, Veil, Chip, Sarong, Bra;
} SKYRDLaundryCL;
signed int CountFilledInLaundries = 0;
// bool FIlledShirt = false, FIlledTShirt = false, FIlledInnerShirt = false, FIlledSocks = false, FIlledSweater = false, FIlledJacket = false, FIlledVest = false, FIlledMukena = false;
// bool FilledKebaya = false, FilledPrayerMat = false, FilledLongPants = false, FilledShortPants = false, FilledInnerPants = false, FilledTowel = false, FilledSkirt = false, FilledHouseDress = false;
// bool FilledMuslimClothing = false, FilledGloves = false, FilledGownDress = false, FilledHandkerchief = false, FilledVeil = false, FilledChip = false, FilledSarong = false, FilledBra = false;

int  main(void);
void AccountRegistrationMenu(bool);
void AccountLoginMenu(bool);
void HomePageMenu(bool);

void ServicesNo01(signed int);
void ServicesNo02(signed int);
void ServicesNo03(signed int);
void OtherServices(bool);
void TopUpBalance(void);
void DepositService(void);
void HistoryService(void);
void CalculatorService(void);
void AccountLogoutMenu(bool);

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
        AdminProfileAccounts.AdminCode[strlen(AdminProfileAccounts.AdminCode) - 1]     = '\0';

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

    if (!ApplicationInLoggedIn) {
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
                    strncpy(GeneratingSaveFile, SignedInAccountUserName, BUFSIZE07); strcat(GeneratingSaveFile, "-USER-SaveFile.dat");

                    RegisteredUserSaveFile = fopen(GeneratingSaveFile, "wb");
                    fwrite(&UserProfileAccounts, sizeof(UserProfileAccounts), 1, RegisteredUserSaveFile);
                    
                    ClearScreen(); fflush(stdin);
                    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                    puts(BRIGHTGREEN156"═════════════════════════════ Starting In :: Logging In ════════════════════════════"ANSI_COLOR_RESET);
                    
                    puts("");
                    printf(BRIGHTBLUE159"\t\tSelamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE159", pengguna atas nama:\n\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Full Name) "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Lengkap:  " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (User Name) "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName);
                    
                    getchar();
                    fclose(RegisteredUserSaveFile); fclose(RegisteredUsers);
                    SignedInAccountSaveFile = fopen(GeneratingSaveFile, "ab");
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
                    strncpy(SignedInAccountAdminCode, AdminProfileAccounts.AdminCode, BUFSIZE07);
                    strncpy(GeneratingSaveFile, SignedInAccountAdminCode, BUFSIZE07); strcat(GeneratingSaveFile, "-ADMIN-SaveFile.dat");

                    RegisteredAdminSaveFile = fopen(GeneratingSaveFile, "wb");
                    fwrite(&AdminProfileAccounts, sizeof(AdminProfileAccounts), 1, RegisteredAdminSaveFile);
                    
                    ClearScreen(); fflush(stdin);
                    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                    puts(BRIGHTGREEN156"═════════════════════════════ Starting In :: Logging In ════════════════════════════"ANSI_COLOR_RESET);
                    
                    puts("");
                    printf(BRIGHTBLUE159"\t\tSelamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE159", operator atas nama:\n\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Full Name)  "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Lengkap:  " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (User Name)  "ANSI_COLOR_RESET BRIGHTBLUE158"Nama Pengguna: " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t"ANSI_COLOR_RESET BRIGHTBLUE158 ANSI_STYLE_ITALIC"> (Admin Code) "ANSI_COLOR_RESET BRIGHTBLUE158"Kode Admin:    " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"%s\n\t\t\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName, AdminProfileAccounts.AdminCode);
                    
                    getchar();
                    fclose(RegisteredAdminSaveFile); fclose(RegisteredAdmins);
                    SignedInAccountSaveFile = fopen(GeneratingSaveFile, "ab");
                    HomePageMenu(ADMIN);
                }
            } fclose(RegisteredAdmins);
            AccountLoginMenu(ADMIN);
        }

    } else { main(); }
}

void AccountLogoutMenu(bool UserMode) {
    char CheckLoggedInAccount[BUFSIZE07];

    if (UserMode == USER) {
        if (strlen(SignedInAccountFullName) != 0 && strlen(SignedInAccountUserName) != 0 && strlen(SignedInAccountAdminCode) == 0) {
            strcpy(CheckLoggedInAccount, SignedInAccountUserName); strcat(CheckLoggedInAccount, "-USER-SaveFile.dat");
            
            if (access(CheckLoggedInAccount, F_OK) == 0) {
                ClearScreen(); fflush(stdin);
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"════════════════════════════ Starting Out :: Logging Out ═══════════════════════════"ANSI_COLOR_RESET);

                puts("");
                printf(BRIGHTMAGENTA217 ANSI_STYLE_BOLD"  Anda telah berhasil logout dari aplikasi " ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD", dengan profil pengguna:\n\n\t"ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"> (Full Name)  "ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD"Nama Lengkap:  " ANSI_STYLE_UNDERLINE"%s\n\t"ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"> (User Name)  "ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD"Nama Pengguna: " ANSI_STYLE_UNDERLINE"%s\n\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName);
                puts(BRIGHTBLUE159"\t\t     Sampai Bertemu Kembali, di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!\n"ANSI_COLOR_RESET);

                SignedInAccountFullName[0] = 0; SignedInAccountUserName[0] = 0;
                ApplicationInLoggedIn = false;
                fclose(SignedInAccountSaveFile);
                getchar(); main();
            }
        }

    } else {
        if (strlen(SignedInAccountFullName) != 0 && strlen(SignedInAccountUserName) != 0 && strlen(SignedInAccountAdminCode) != 0) {
            strcpy(CheckLoggedInAccount, SignedInAccountUserName); strcat(CheckLoggedInAccount, "-ADMIN-SaveFile.dat");
            
            if (access(CheckLoggedInAccount, F_OK) == 0) {
                ClearScreen(); fflush(stdin);
                puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
                puts(BRIGHTGREEN156"════════════════════════════ Starting Out :: Logging Out ═══════════════════════════"ANSI_COLOR_RESET);

                puts("");
                printf(BRIGHTMAGENTA217 ANSI_STYLE_BOLD"  Anda telah berhasil logout dari aplikasi " ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD", dengan profil operator:\n\n\t"ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"> (Full Name)  "ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD"Nama Lengkap:  " ANSI_STYLE_UNDERLINE"%s\n\t"ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"> (User Name)  "ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD"Nama Pengguna: " ANSI_STYLE_UNDERLINE"%s\n\n"ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"> (Admin Code) "ANSI_COLOR_RESET BRIGHTPINK219 ANSI_STYLE_BOLD"Kode Admin:    " ANSI_STYLE_UNDERLINE"%s\n\n"ANSI_COLOR_RESET, SignedInAccountFullName, SignedInAccountUserName, SignedInAccountAdminCode);
                puts(BRIGHTBLUE159"\t\t     Sampai Bertemu Kembali, di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry"ANSI_COLOR_RESET BRIGHTBLUE158"!\n"ANSI_COLOR_RESET);

                SignedInAccountFullName[0] = 0; SignedInAccountUserName[0] = 0; SignedInAccountAdminCode[0] = 0;
                ApplicationInLoggedIn = false;
                fclose(SignedInAccountSaveFile);
                getchar(); main();
            }
        }
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
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);

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
            
            puts("");
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
            case 99: OtherServices(USER); break;
            default: HomePageMenu(USER); break;
        }

    } else {
        ClearScreen();
        puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
        puts(BRIGHTGREEN155"═════════════════════════════ In Progress :: Dashboard ═════════════════════════════"ANSI_COLOR_RESET);
        puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"══════════════════════════════════ Home Page Menu ══════════════════════════════════"ANSI_COLOR_RESET);

        printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: ADMIN) Sinkronisasi: %s-%s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName, SignedInAccountAdminCode);
        printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);
        getchar();
        HomePageMenu(ADMIN);
    }
}

void ServicesNo01(signed int ServiceOption) {
    int ValidIntInput;
    signed int CheckListOn, AmountOfLaundries = 0;

    if (ServiceOption == 1) {
        do {
            ClearScreen();
            puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN155"══════════════════════════════ In Progress :: Service ══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"═══════════════════════════ Service Room 01 ➡ 💐 Regular ═══════════════════════════"ANSI_COLOR_RESET);

            printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n"ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"═════════════════════════════ CUCI KILOAN (per. kg) ════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"════════════════════════════ DAFTAR CEK-LIST PAKAIAN ═══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE213 ANSI_STYLE_BOLD"Asertif Banyak Tipe Pakaian: 24 Tipe (per. 8 baris, 3 kolom)\n");
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"Catatan: (akumulasi banyak pakaian akan ditimbang untuk dihitung massa total"ANSI_COLOR_RESET);
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"         pakaian dari yang memesan layanan D'Laundry dalam format: Rp6.000,00/kg)."ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTMAGENTA210"[01] Kaos           [09] Kebaya             [17] Baju Muslim"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[02] Kemeja         [10] Sajadah            [18] Sarung Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[03] Kaos Dalam     [11] Celana Panjang     [19] Gaun"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[04] Kaos Kaki      [12] Celana Pendek      [20] Sapu Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[05] Sweater        [13] Celana Dalam       [21] Kerudung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[06] Jaket          [14] Handuk             [22] Ciput"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[07] Rompi          [15] Rok                [23] Sarung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[08] Mukena         [16] Daster             [24] Bra"ANSI_COLOR_RESET);
            puts(BRIGHTRED216 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [0] untuk kembali ke menu utama program... ."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [99] untuk mengkonfirmasi isi laundry... ."ANSI_COLOR_RESET);

            puts("");
            printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &CheckListOn); fflush(stdin);
        } while (ValidIntInput == 0);

        switch (CheckListOn) {
            case 0:
                HomePageMenu(USER); break;
            
            /* NOTE: First 8 rows and first column... */
            case 1:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Shirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Shirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 2:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(T-Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kemeja\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.TShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.TShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 3:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 4:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Socks)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Kaki\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Socks = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Socks = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 5:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sweater)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Switer\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sweater = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sweater = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 6:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Jacket)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Jaket\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Jacket = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Jacket = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 7:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Vest)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rompi\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Vest = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Vest = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 8:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Mukena)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Mukena\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Mukena = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Mukena = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Second 8 rows and second column... */
            case 9:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Kebaya)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kebaya\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Kebaya = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Kebaya = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 10:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Prayer Mat)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sajadah\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.PrayerMat = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.PrayerMat = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 11:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Long Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Panjang\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.LongPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.LongPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 12:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Short Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Pendek\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.ShortPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.ShortPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 13:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 14:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Towel)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Handuk\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Towel = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Towel = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 15:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Skirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rok\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Skirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Skirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 16:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(House Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Daster\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.HouseDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.HouseDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Third 8 rows and third column... */
            case 17:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Muslim Clothing)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Baju Muslim\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.MuslimClothing = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.MuslimClothing = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 18:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gloves)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Gloves = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Gloves = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 19:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gown Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Gaun\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.GownDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.GownDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 20:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Handkerchief)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sapu Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Handkerchief = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Handkerchief = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 21:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Veil)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kerudung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Veil = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Veil = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 22:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Chip)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Ciput\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Chip = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Chip = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 23:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sarong)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sarong = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sarong = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 24:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Bra)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Bra\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Bra = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Bra = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;

            default: ServicesNo01(1); break;
        }

    } else if (ServiceOption == 2) {
        do {
            ClearScreen();
            puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN155"══════════════════════════════ In Progress :: Service ══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"═══════════════════════════ Service Room 02 ➡ 💐 Express ═══════════════════════════"ANSI_COLOR_RESET);

            printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n"ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"═════════════════════════════ CUCI KILOAN (per. kg) ════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"════════════════════════════ DAFTAR CEK-LIST PAKAIAN ═══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE213 ANSI_STYLE_BOLD"Asertif Banyak Tipe Pakaian: 24 Tipe (per. 8 baris, 3 kolom)\n");
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"Catatan: (akumulasi banyak pakaian akan ditimbang untuk dihitung massa total"ANSI_COLOR_RESET);
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"         pakaian dari yang memesan layanan D'Laundry dalam format: Rp6.000,00/kg)."ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTMAGENTA210"[01] Kaos           [09] Kebaya             [17] Baju Muslim"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[02] Kemeja         [10] Sajadah            [18] Sarung Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[03] Kaos Dalam     [11] Celana Panjang     [19] Gaun"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[04] Kaos Kaki      [12] Celana Pendek      [20] Sapu Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[05] Sweater        [13] Celana Dalam       [21] Kerudung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[06] Jaket          [14] Handuk             [22] Ciput"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[07] Rompi          [15] Rok                [23] Sarung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[08] Mukena         [16] Daster             [24] Bra"ANSI_COLOR_RESET);
            puts(BRIGHTRED216 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [0] untuk kembali ke menu utama program... ."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [99] untuk mengkonfirmasi isi laundry... ."ANSI_COLOR_RESET);

            puts("");
            printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &CheckListOn); fflush(stdin);
        } while (ValidIntInput == 0);

        switch (CheckListOn) {
            case 0:
                HomePageMenu(USER); break;
            
            /* NOTE: First 8 rows and first column... */
            case 1:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Shirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Shirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 2:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(T-Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kemeja\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.TShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.TShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 3:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 4:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Socks)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Kaki\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Socks = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Socks = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 5:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sweater)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Switer\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sweater = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sweater = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 6:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Jacket)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Jaket\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Jacket = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Jacket = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 7:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Vest)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rompi\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Vest = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Vest = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 8:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Mukena)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Mukena\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Mukena = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Mukena = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Second 8 rows and second column... */
            case 9:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Kebaya)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kebaya\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Kebaya = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Kebaya = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 10:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Prayer Mat)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sajadah\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.PrayerMat = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.PrayerMat = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 11:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Long Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Panjang\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.LongPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.LongPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 12:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Short Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Pendek\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.ShortPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.ShortPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 13:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 14:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Towel)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Handuk\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Towel = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Towel = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 15:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Skirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rok\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Skirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Skirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 16:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(House Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Daster\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.HouseDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.HouseDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Third 8 rows and third column... */
            case 17:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Muslim Clothing)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Baju Muslim\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.MuslimClothing = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.MuslimClothing = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 18:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gloves)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Gloves = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Gloves = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 19:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gown Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Gaun\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.GownDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.GownDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 20:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Handkerchief)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sapu Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Handkerchief = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Handkerchief = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 21:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Veil)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kerudung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Veil = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Veil = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 22:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Chip)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Ciput\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Chip = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Chip = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 23:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sarong)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sarong = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sarong = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 24:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Bra)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Bra\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Bra = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Bra = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;

            default: ServicesNo01(1); break;
        }

    } else if (ServiceOption == 3) {
        do {
            ClearScreen();
            puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN155"══════════════════════════════ In Progress :: Service ══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156"═══════════════════════════ Service Room 02 ➡ 💐 Instant ═══════════════════════════"ANSI_COLOR_RESET);

            printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n"ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"═════════════════════════════ CUCI KILOAN (per. kg) ════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"════════════════════════════ DAFTAR CEK-LIST PAKAIAN ═══════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTPURPLE213 ANSI_STYLE_BOLD"Asertif Banyak Tipe Pakaian: 24 Tipe (per. 8 baris, 3 kolom)\n");
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"Catatan: (akumulasi banyak pakaian akan ditimbang untuk dihitung massa total"ANSI_COLOR_RESET);
            puts(BRIGHTRED209 ANSI_STYLE_BOLD"         pakaian dari yang memesan layanan D'Laundry dalam format: Rp6.000,00/kg)."ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTMAGENTA210"[01] Kaos           [09] Kebaya             [17] Baju Muslim"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[02] Kemeja         [10] Sajadah            [18] Sarung Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[03] Kaos Dalam     [11] Celana Panjang     [19] Gaun"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[04] Kaos Kaki      [12] Celana Pendek      [20] Sapu Tangan"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[05] Sweater        [13] Celana Dalam       [21] Kerudung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[06] Jaket          [14] Handuk             [22] Ciput"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[07] Rompi          [15] Rok                [23] Sarung"ANSI_COLOR_RESET);
            puts(BRIGHTMAGENTA210"[08] Mukena         [16] Daster             [24] Bra"ANSI_COLOR_RESET);
            puts(BRIGHTRED216 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [0] untuk kembali ke menu utama program... ."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [99] untuk mengkonfirmasi isi laundry... ."ANSI_COLOR_RESET);

            puts("");
            printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &CheckListOn); fflush(stdin);
        } while (ValidIntInput == 0);

        switch (CheckListOn) {
            case 0:
                HomePageMenu(USER); break;
            
            /* NOTE: First 8 rows and first column... */
            case 1:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Shirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Shirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 2:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(T-Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kemeja\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.TShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.TShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 3:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Shirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerShirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerShirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 4:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Socks)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kaos Kaki\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Socks = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Socks = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 5:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sweater)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Switer\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sweater = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sweater = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 6:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Jacket)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Jaket\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Jacket = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Jacket = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 7:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Vest)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rompi\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Vest = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Vest = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 8:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Mukena)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Mukena\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Mukena = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Mukena = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Second 8 rows and second column... */
            case 9:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Kebaya)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kebaya\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Kebaya = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Kebaya = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 10:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Prayer Mat)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sajadah\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.PrayerMat = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.PrayerMat = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 11:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Long Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Panjang\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.LongPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.LongPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 12:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Short Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Pendek\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.ShortPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.ShortPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 13:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Inner Pants)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Celana Dalam\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.InnerPants = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.InnerPants = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 14:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Towel)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Handuk\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Towel = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Towel = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 15:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Skirt)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Rok\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Skirt = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Skirt = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 16:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(House Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Daster\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.HouseDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.HouseDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            
            /* NOTE: Third 8 rows and third column... */
            case 17:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Muslim Clothing)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Baju Muslim\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.MuslimClothing = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.MuslimClothing = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 18:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gloves)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Gloves = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Gloves = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 19:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Gown Dress)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Gaun\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.GownDress = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.GownDress = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 20:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Handkerchief)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sapu Tangan\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Handkerchief = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Handkerchief = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 21:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Veil)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Kerudung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Veil = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Veil = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 22:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Chip)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Ciput\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Chip = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Chip = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 23:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Sarong)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Sarung\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Sarong = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Sarong = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;
            case 24:
                do {
                    puts("");
                    puts(BRIGHTPURPLE218 ANSI_STYLE_BOLD"Banyaknya \"" ANSI_STYLE_ITALIC"(Bra)"ANSI_COLOR_RESET BRIGHTPURPLE218 ANSI_STYLE_BOLD" Bra\" yang akan diproses dalam layanan D'Laundry?"ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &AmountOfLaundries); fflush(stdin);
                } while (ValidIntInput == 0);
                if (AmountOfLaundries != 0) {
                    SKYRDLaundryCL.Bra = AmountOfLaundries;
                    (CountFilledInLaundries < 24) ? CountFilledInLaundries++ : 0;
                } else {
                    SKYRDLaundryCL.Bra = 0;
                    (CountFilledInLaundries > 0)  ? CountFilledInLaundries-- : 0;
                } ServicesNo01(1); break;

            default: ServicesNo01(1); break;
        }
    }
}

void ServicesNo02(signed int ServiceOption) {
    ClearScreen();
    puts("ServicesNo02();");
    getchar(); HomePageMenu(USER);
}

void ServicesNo03(signed int ServiceOption) {
    ClearScreen();
    puts("ServicesNo03();");
    getchar(); HomePageMenu(USER);
}

void OtherServices(bool UserMode) {
    int ValidIntInput;
    signed int OtherServicesOption;

    if (UserMode == USER) {
        do {
            ClearScreen();
            puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN155"═════════════════════════════ In Progress :: Dashboard ═════════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"══════════════════════════════════ Home Page Menu ══════════════════════════════════"ANSI_COLOR_RESET);

            printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
            printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);

            puts("");
            puts(BRIGHTRED216 ANSI_STYLE_BOLD"════════════════════════ LAYANAN MENU LAINNYA (UTILITAS) ═══════════════════════════"ANSI_COLOR_RESET);
            puts(BRIGHTRED216"[1] 🌟 Top-Up Saldo       @SKYRD'Laundry ⏩ (Debit, Kredit, E-Wallet)             😋"ANSI_COLOR_RESET);
            puts(BRIGHTRED216"[2] 🌹 Layanan Setoran    @SKYRD'Laundry ⏩ (Setoran, Progress, Status)           🤗"ANSI_COLOR_RESET);
            puts(BRIGHTRED216"[3] 🍀 Layanan Riwayat    @SKYRD'Laundry ⏩ (Riwayat, Umpan Balik)                😇"ANSI_COLOR_RESET);
            puts(BRIGHTRED216"[4] 💫 Layanan Kalkulator @SKYRD'Laundry ⏩ (Perkiraan Harga, Cek Paket)          🤩"ANSI_COLOR_RESET);
            puts(BRIGHTBLUE159 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [0] untuk kembali ke menu utama program... ."ANSI_COLOR_RESET);
            puts(BRIGHTGREEN156 ANSI_STYLE_BOLD ANSI_STYLE_ITALIC"➡ Ketik [99] untuk logout dan/atau menutup program... ."ANSI_COLOR_RESET);

            puts("");
            printf(ANSI_COLOR_WHITE"[INPUT] > "); ValidIntInput = scanf("%d", &OtherServicesOption); fflush(stdin);
        } while (ValidIntInput == 0);

        switch (OtherServicesOption) {
            case 0:  HomePageMenu(USER); break;
            case 1:  TopUpBalance(); break;
            case 2:  DepositService(); break;
            case 3:  HistoryService(); break;
            case 4:  CalculatorService(); break;
            case 99: AccountLogoutMenu(USER); break;
            default: OtherServices(USER); break;
        }
    }
}

void TopUpBalance(void) {
    ClearScreen();
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN155"═════════════════════ In Progress :: Additional/Other Services ═════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"══════════════════════════════════ Top-Up Balance ══════════════════════════════════"ANSI_COLOR_RESET);

    printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
    printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);
}

void DepositService(void) {
    ClearScreen();
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN155"═════════════════════ In Progress :: Additional/Other Services ═════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"═════════════════════════════════ Deposit Services ══════════════════════════════════"ANSI_COLOR_RESET);

    printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
    printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);
}

void HistoryService(void) {
    ClearScreen();
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN155"═════════════════════ In Progress :: Additional/Other Services ═════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"═════════════════════════════════ History Services ══════════════════════════════════"ANSI_COLOR_RESET);

    printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
    printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);
}

void CalculatorService(void) {
    ClearScreen();
    puts(BRIGHTGREEN154"══════════════════════════════════ SKYR D'Laundry ══════════════════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN155"═════════════════════ In Progress :: Additional/Other Services ═════════════════════"ANSI_COLOR_RESET);
    puts(BRIGHTGREEN156 ANSI_STYLE_BOLD"═══════════════════════════════ Calculator* Services ══════════════════════════════════"ANSI_COLOR_RESET);

    printf(BRIGHTPINK219 ANSI_STYLE_BOLD"(STATUS: USER) Sinkronisasi: %s\n\n"ANSI_COLOR_RESET, SignedInAccountUserName);
    printf(BRIGHTBLUE159"\t\t\t  Selamat Datang di " ANSI_STYLE_BOLD ANSI_STYLE_UNDERLINE"SKYR D'Laundry!"ANSI_COLOR_RESET "\n\t\t\t  " BRIGHTBLUE158 ANSI_STYLE_ITALIC"@PRE-RELEASE V1.0.0; (14/12/2023)\n\n\t\t  "ANSI_COLOR_RESET BRIGHTMAGENTA217 ANSI_STYLE_BOLD"Layanan apakah yang ingin Anda kunjungi saat ini?\n"ANSI_COLOR_RESET);
}

int main(void) {
    SetConsoleOutputCP(65001);

    char USERCheckLoggedInAccount[BUFSIZE07], ADMINCheckLoggedInAccount[BUFSIZE07];
    int ValidIntInput = 0;
    signed int LoginOption, LoginMode;
    bool UserMode;

    // printf("%d\n", ApplicationInLoggedIn);
    // getchar();

    if (!ApplicationInLoggedIn) {
        if (FirstRuntimeExecution) {
            MatchSaveFileTxt("./", "-SaveFile");
            for (int i = 0; i < BUFSIZE10; i++) {
                // puts(SaveFilesTxtName[i].FileNames);
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
                } break;
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
                } break;
            default: main(); break;
        }

    } else {
        if (strlen(SignedInAccountFullName) != 0 && strlen(SignedInAccountUserName) != 0) {
            strcpy(USERCheckLoggedInAccount, SignedInAccountUserName);  strcat(USERCheckLoggedInAccount, "-USER-SaveFile.dat");
            strcpy(ADMINCheckLoggedInAccount, SignedInAccountUserName); strcat(ADMINCheckLoggedInAccount, "-ADMIN-SaveFile.dat");
            
            if      (access(USERCheckLoggedInAccount, F_OK) == 0 && strlen(SignedInAccountAdminCode) == 0) { UserMode = USER; }
            else if (access(ADMINCheckLoggedInAccount, F_OK) == 0 && strlen(SignedInAccountAdminCode) > 0) { UserMode = ADMIN; }
        } HomePageMenu(UserMode);
    } return 0;
}