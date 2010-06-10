/*******************************************************
*   YLanguageClass©
*
*   Quick and dirty way of loading up language files
*   for apps. Verry simple and powerful :)
*
*   @author  YNOP(ynop@acm.org) 
*   @version 1.0.0
*   @date    May 4 2000
*******************************************************/
#ifndef _YLANGUAGE_CLASS_H_
#define _YLANGUAGE_CLASS_H_

#include <map>

#include <String.h>

#include <string.h>

/*******************************************************
*   Used as part of the lang list for comparting two
*   strings. STL is funny like that. 
*******************************************************/
struct ltstr{ 
   bool operator()(const char* s1, const char* s2) const{
      return strcmp(s1, s2) < 0;
   }
};

class YLanguageClass{
   public:
      /*******************************************************
      *   Constructs a empty Language class. A call to 
      *   initCheck after constructing will return B_NO_INIT.
      *   You need to call SetName() or this class is useless
      *******************************************************/
      YLanguageClass();
      
      /*******************************************************
      *   Returs the status of the lang class. Only usefull
      *   after SetName and get
      *******************************************************/
      status_t InitCheck();
      
      /*******************************************************
      *   Gets a string based upon the key. If no entry of 
      *   key is found it will return the key itself. A call
      *   to InitCheck will return B_OK if we found a key and
      *   B_ERROR otherwise.
      *******************************************************/
      const char* get(char* key);
      
      /*******************************************************
      *   Returns the current language file name as set by 
      *   SetName()
      *******************************************************/
      const char* Name();
      
      /*******************************************************
      *   Sets the name of the Language file to be used. 
      *   All language files should be stored in a directory
      *   called "Languages" under the Application directory.
      *   By calling set name you also invoke LoadLang which
      *   reads in and inits the lang class to the new language
      *   If all went as planned a call to InitCheck will 
      *   return B_OK. If the file did not exist the aproprite
      *   error code will be returned. Any other error will
      *   return B_ERROR.
      *******************************************************/
      void SetName(char* name);
      
   private:
      void LoadLang();
      BString ReadLine(BFile*);
      void set(const char*, const char*);
      
      status_t our_status;
      BString LName;
      map <const char*,const char*,ltstr>LangList;
};

extern YLanguageClass Language; // Included so you don't have too 
#endif
