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

%ClassName% &%ClassName%::operator=(%ClassName% &rhs)
{
    if(this == &rhs) return *this;
    d->copyFrom(rhs.d);
    return *this;
}

%ClassName%::~%ClassName%()
{
    delete d;
}
@endif