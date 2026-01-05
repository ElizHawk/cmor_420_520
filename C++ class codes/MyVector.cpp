class MyVector{
public:
  MyVector(int length);
  MyVector(MyVector & copy_from);
  MyClass & operator=(MyClass & copy_from);
  ~MyVector();  

  int get_length(void);
  double get_index(int index);
  void set_index(int index, double val);
private:
  int length_;
  double * data_;
};
