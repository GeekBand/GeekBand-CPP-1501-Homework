class FileSpliter;

class MainForm : public Form {
private:
  TestBox* txtFilePath;
  TextBox* txtFileNumber;
  ProgressBar* progressBar;
  List<FileSpliter*> *_observers;
public:
  void Butten1_Click() {
    // do click
    Notify();
  }
  virtual void Attach(FileSpliter* o) {
    _observers->Append(o);
  }
  virtual void Detach(FileSpliter* o) {
    _observers->Remove(o);
  };
  virtual void Notify() {
    for obs in _observers {
      obs->Update(this);
    }
  };
protected:
  MainForm() {}
};

class FileSplitter {
private:
  string filePath;
  int fileNumber;
public:
  virtual void Split() = 0;
  virtual void Update(MainForm*) = 0;
  virtual ~FileSplitter() {}
};

class SpliterA : public FileSplitter {
private:
  MainForm* _subject;
public:
  SpliterA(MainForm* mf) {
    _subject = mf;
    _subject->Attach(this);
  }
  virtual ~SpliterA() {
    _subject->Detach(this);
  }
  virtual void Update(MainForm *mf) {
    if (mf == _subject) {
      Split()
    }
  }
  virtual void Split() {
    // split algorithm A
  }
};

class SpliterB : public FileSplitter {
private:
  MainForm* _subject;
public:
  SpliterB(MainForm* mf) {
    _subject = mf;
    _subject->Attach(this);
  }
  virtual ~SpliterB() {
    _subject->Detach(this);
  }
  virtual void Update(MainForm *mf) {
    if (mf == _subject) {
      Split()
    }
  }
  virtual void Split() {
    // split algorithm C
  }
};

class SpliterC : public FileSplitter {
private:
  MainForm* _subject;
public:
  SpliterC(MainForm* mf) {
    _subject = mf;
    _subject->Attach(this);
  }
  virtual ~SpliterC() {
    _subject->Detach(this);
  }
  virtual void Update(MainForm *mf) {
    if (mf == _subject) {
      Split()
    }
  }
  virtual void Split() {
    // split algorithm C
  }
};

int main() {
  MainForm* mf = new MainForm();
  SpliterA* spa = new SpliterA(mf);
  SpliterB* spa = new SpliterB(mf);
  SpliterC* spa = new SpliterC(mf);
  return 0;
}
