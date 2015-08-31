#include "FileSplitter.h"

int FileSplitter::doSplit()
{
	// Pseudo code begin
	foreach filePath do split by fileNumber use algo;
	while split call callback function.
	// Pseudo code end
	return 0;
}

public void MainForm::Button1_Click()
{
	FileSplitterAlgo * pAlgo = new FileSplitterAlgo1();
	
	FileSplitter * fileSplitter = new FileSplitter(txtFilePath->text, txtFileNumber->txt, pAlgo, [this](int precent){ this->progressBar.value = precent; });
	if ( fileSplitter )
	{
		fileSplitter->doSplit();
		delete fileSplitter;
	}
	
	if ( pAlgo )
	{
		delete pAlgo);
	}
}

int main()
{
	MainForm * myForm = new MainForm();
	
	return 0;
}