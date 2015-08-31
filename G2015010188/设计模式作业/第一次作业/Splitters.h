#pragma once
#include "FileSplitter.h"

class VideoFileSplitter : public FileSplitter {
public:
	VideoFileSplitter(string& _filepath, int _filenumber, void(*updateFun)(int)):FileSplitter(_filepath, _filenumber, updateFun) {}

	void Split() {
		//for ...do 
		NotificationUpdate(/*process Value*/1);
		//...do
	}
};

class MusicFileSplitter : public FileSplitter {
public:
	MusicFileSplitter(string& _filepath, int _filenumber, void(*updateFun)(int)) :
		FileSplitter(_filepath, _filenumber, updateFun) {}

	void Split() {
		//for ...do 
		NotificationUpdate(/*process Value*/1);
		//...do
	}
};

class TextFileSplitter : public FileSplitter {
public:
	TextFileSplitter(string& _filepath, int _filenumber, void(*updateFun)(int)) :
		FileSplitter(_filepath, _filenumber, updateFun) {}

	void Split() {
		//for ...do 
		NotificationUpdate(/*process Value*/1);
		//...do
	}
};