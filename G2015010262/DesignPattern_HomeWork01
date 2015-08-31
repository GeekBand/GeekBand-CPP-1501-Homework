#include <iostream>
#include <list>
#include "stdafx.h"
using namespace std;

//Bass Class for Split Method
class BaseSplitMethod
{
public:
  virtual ~BaseSplitMethod (){}
  virtual void Split ( string, int ) = 0;
};

//Concrete Split Method A
class ConcreteSplitMethodA : public BaseSplitMethod
{
public:
  virtual void Split ( string, int ){
    //......
  }
};

//Concrete Split Method B
class ConcreteSplitMethodB : public BaseSplitMethod
{
public:
  virtual void Split ( string, int ){
    //......
  }
};

//Concrete Split Method C
class ConcreteSplitMethodC : public BaseSplitMethod
{
public:
  virtual void Split ( string, int ){
    //......
  }
};

//Base Class/Interface for Progress 
class IProgress{
public:
  virtual ~IProgress (){};
  virtual void DoProgress ( float value ) = 0;
};

//Concrete Progress Class 
class ConsoleNotifier : public IProgress {
public:
  virtual void DoProgress ( float value ){
    cout << ".";
  }
};

//FileSplitter Class
class FileSplitter
{
private:
  string filePath;
  int fileNumber;
  list<IProgress*> progressList;
  BaseSplitMethod* splitMethod;

public:
  FileSplitter ( string filePath_, int fileNumber_, BaseSplitMethod* splitMethod_ )
    :filePath ( filePath_ ), fileNumber ( fileNumber_ ), splitMethod ( splitMethod_ )
  {
  }

  void addIProgress ( IProgress* progress ){
    progressList.push_back ( progress );
  }

  void removeIProgress ( IProgress* progress ){
    progressList.remove ( progress );
  }

  void Split ()
  {
    //1.读取大文件

    //2.分批次向小文件中写入
    for (int i = 0; i < fileNumber; i++)
    {
      float progressValue;
      splitMethod->Split ( filePath, i );
      NotifyProgressList ( progressValue );
    }

  }

protected:
  void NotifyProgressList ( float value )
  {
    list<IProgress*>::iterator itor;

    for (itor = progressList.begin (); itor != progressList.end (); itor++)
    {
      (*itor)->DoProgress ( value );
    }
  }
};


//MainForm Class
class MainForm : public Form, public IProgress
{
private:
  TextBox* txtFilePath;
  TextBox* txtFileNumber;
  ProgressBar* progressBar;

  BaseSplitMethod* splitMethod;
  
public:
  void Button1_Click ()
  {
    string filePath = txtFilePath->getText ();
    int number = atoi ( txtFileNumber->getText ().c_str () );

    ConsoleNotifier cn;

    splitMethod = new ConcreteSplitMethodA ();

    FileSplitter fileSplitter ( txtFilePath.GetWindowText, (int)txtFileNumber.GetWindowText, splitMethod);

    fileSplitter.addIProgress ( this );
    fileSplitter.addIProgress ( &cn );
    
    fileSplitter.Split ();

  }

  virtual void DoProgress ( float value ){
    progressBar->setValue ( value );
  }
};
