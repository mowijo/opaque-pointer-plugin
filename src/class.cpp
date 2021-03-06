#include "%ClassName%.%CppHeaderSuffix%"

@if "%InheritsQObject%" == "true"
class %ClassName%Private : public QObject
{
  
  Q_OBJECT
  
    %ClassName% *owner;

public:

    %ClassName%Private(%ClassName% *o)
        : QObject(o), owner(o)
    {
    }

};

#include "%ClassName%.moc"


%ClassName%::%ClassName%(QObject *parent) 
  : QObject(parent)
{
    d = new %ClassName%Private(this);
}

@else
class %ClassName%Private
{
    %ClassName% *owner;

public:

    %ClassName%Private(%ClassName% *o)
        : owner(o)
    {
    }

    void copyFrom(%ClassName%Private *other)
    {
    }
};

%ClassName%::%ClassName%()
{
    d = new %ClassName%Private(this);
}

%ClassName%::%ClassName%(const %ClassName% &other)
{
    d = new %ClassName%Private(this);
    if(this == &other) return;
    d->copyFrom(other.d);
}
@if "%MoveConstructor%" == "true"
%ClassName%::%ClassName%(%ClassName%&& other)
{
  d = other.d;
  other.d = 0;
}
@endif

%ClassName% &%ClassName%::operator=(const %ClassName% &rhs)
{
    if(this == &rhs) return *this;
    d->copyFrom(rhs.d);
    return *this;
}

%ClassName%::~%ClassName%()
{
@if "%MoveConstructor%" == "true"
    if(d) delete d;
@else
    delete d;
@endif 
}
@endif
