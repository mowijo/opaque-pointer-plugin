#ifndef %ClassName:u%_H
#define %ClassName:u%_H
@if "%InheritsQObject%" == "true"

#include <QObject>
  
class %ClassName% : public QObject
{  
    
  Q_OBJECT
  
public:
  explicit %ClassName%(QObject *parent = 0);

private:
  friend class %ClassName%Private;
  class %ClassName%Private *d;
};
@else

class %ClassName% 
{  
    
public:

  %ClassName%();
  %ClassName%(const %ClassName% &other);
  %ClassName%& operator=(%ClassName% &rhs);
  ~%ClassName%();


private:
  friend class %ClassName%Private;
  class %ClassName%Private *d;
};
@endif

#endif // %ClassName:u%_H
