/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== READ ME.rtf ==================
static const unsigned char temp_binary_data_0[] =
"{\\rtf1\\ansi\\ansicpg1252\\cocoartf1671\\cocoasubrtf500\n"
"{\\fonttbl\\f0\\fswiss\\fcharset0 Helvetica;\\f1\\fswiss\\fcharset0 Helvetica-Bold;}\n"
"{\\colortbl;\\red255\\green255\\blue255;}\n"
"{\\*\\expandedcolortbl;;}\n"
"\\margl1440\\margr1440\\vieww10800\\viewh8400\\viewkind0\n"
"\\pard\\tx720\\tx1440\\tx2160\\tx2880\\tx3600\\tx4320\\tx5040\\tx5760\\tx6480\\tx7200\\tx7920\\tx8640\\pardirnatural\\partightenfactor0\n"
"\n"
"\\f0\\fs24 \\cf0 To get maximilian into juce\\\n"
"\\\n"
"step 1. \\\n"
"\t-Create a audio/plug-in project\\\n"
"\t\\\n"
"step 2.\\\n"
"\t-Go to \n"
"\\f1\\b Debug\n"
"\\f0\\b0 \\\n"
"\t-Under \\'93\n"
"\\f1\\b Header Search Paths\n"
"\\f0\\b0 \\'94 drag maximilian library folder into field giving it a search path\\\n"
"\t\\\n"
"step 3.\\\n"
"\t-In file explorer drag maximilian library folder into \n"
"\\f1\\b source folder\\\n"
"\\\n"
"\n"
"\\f0\\b0 step 4.\\\n"
"\t-Add \n"
"\\f1\\b #include \\'93maximilian.h\\'94 \n"
"\\f0\\b0 to project}";

const char* READ_ME_rtf = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xef0b3e06:  numBytes = 785; return READ_ME_rtf;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "READ_ME_rtf"
};

const char* originalFilenames[] =
{
    "READ ME.rtf"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
