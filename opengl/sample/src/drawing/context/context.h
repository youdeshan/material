#ifndef ICONTEXT_H
#define ICONTEXT_H

class IContext  {
public:
  virtual ~IContext() {};

  virtual void SetCurrent() {}

protected:
  IContext() {}
};

#endif // ICONTEXT_H
