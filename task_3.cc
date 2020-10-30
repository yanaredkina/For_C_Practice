/* VVO-2course - Redkina Yana - TASK 3 */

#include <iostream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

/*-------------- CLASS BODY -------------- */
class Body {
public:
    virtual ~Body() {
        cout << "~Body()" << endl;
    }
    
    virtual int area() const = 0;
    
    virtual string class_name() {
        return "Body";
    }

    virtual void print() {
        cout << class_name() << "()" << endl;
    }
    
    virtual void print_content() {
    }
};

/*-------------- CLASS BOX -------------- */

class Box: public Body {
private:
    int length;
    int width;
    int height;
public:
    Box() {
        length = width = height = 0;
    }
    
    Box(int n) {
        if (n < 0) {
            throw range_error("parameter is negative");
        }
        length = width = height = n;
    }
    
    Box(int l, int h) {
        if (l < 0 || h < 0) {
            throw range_error("some parameters is negative");
        }
        length = l;
        width = l;
        height = h;
    }
    
    Box(int l, int w, int h) {
        if (l < 0 || w < 0 || h < 0) {
            throw range_error("some parameters is negative");
        }
        length = l;
        width = w;
        height = h;
    }
    
    Box(const Box & b) {
        length = b.length;
        width = b.width;
        height = b.height;
    }
    
    virtual ~Box() {
        cout << "~Box()" << endl;
    }

    int get_l() const {
        return length;
    }

    int get_w() const {
        return width;
    }

    int get_h() const {
        return height;
    }
    
    void set_l(int m) {
        if (m < 0) {
            throw range_error("parameter is negative");
        }
        length = m;
    }

    void set_w(int m) {
        if (m < 0) {
            throw range_error("parameter is negative");
        }
        width = m;
    }

    void set_h(int m) {
        if (m < 0) {
            throw range_error("parameter is negative");
        }
        height = m;
    }

    virtual int area() const {
        return (2 * height * length + 2 * width * height + length * width);
    }
    
    virtual string class_name() {
        return "Box";
    }

    virtual void print() {
        cout << class_name() << "(";
        print_content();
        cout << ", area: " << area() << ")" << endl;
    }
    
    virtual void print_content() {
       cout << "length: " << length << ", width: " << width << ", height: " << height;
    }

    Box & operator = (const Box & b) {
        length = b.length;
        width = b.width;
        height = b.height;
        return *this;
    }
    
    /* ++Box */
    Box operator ++ () {
        ++length;
        ++width;
        ++height;
        Box res (*this);
    return res;
    }

    /* Box++ */
    Box operator ++ (int) {
        Box res (*this);
        ++length;
        ++width;
        ++height;
    return res;
    }
    
    /* --Box */
    Box operator -- () {
        --length;
        if (length < 0) {
            throw range_error("parameter is negative");
        }
        --width;
        if (width < 0) {
            throw range_error("parameter is negative");
        }
        --height;
        if (height < 0) {
            throw range_error("parameter is negative");
        }
        Box res (*this);
    return res;
    }

    /* Box-- */
    Box operator -- (int) {
        Box res (*this);
        --length;
        if (length < 0) {
            throw range_error("parameter is negative");
        }
        --width;
        if (width < 0) {
            throw range_error("parameter is negative");
        }
        --height;
        if (height < 0) {
            throw range_error("parameter is negative");
        }
        return res;
    }
    
    friend Box operator + (const Box & a, const Box & b); 
};
    
    Box operator + (const Box & a, const Box & b) {
        Box res;
        res.length = a.length + b.length;
        res.width = a.width + b.width;
        res.height = a.height + b.height;
        return res;
    }

/*-------------- CLASS WBOX -------------- */

class WBox: public virtual Box {
private:
    int w_length;
    int w_width;
public:
    WBox(): Box() {
        w_length = w_width = 0;
    }
    
    WBox(int n): Box() {
        if (n < 0) {
            throw range_error("parameter is negative");
        }
        w_length = w_width = n;
    }
    
    WBox(int win_l, int win_w): Box() {
        if (win_l < 0 || win_w < 0) {
            throw range_error("some parameters is negative");
        }
        w_length = win_l;
        w_width = win_w;
    }
    
    WBox(int n, int win_l, int win_w): Box(n) {
        if (win_l < 0 || win_w < 0) {
            throw range_error("some parameters is negative");
        }
        if (win_l >= n || win_w >= n) {
            throw range_error("parameters of window is incorrect");
        }
        w_length = win_l;
        w_width = win_w;
    }
    
    WBox(int l, int h, int win_l, int win_w): Box(l, h) {
        if (win_l < 0 || win_w < 0) {
            throw range_error("some parameters is negative");
        }
        if (win_l >= l || win_w >= h) {
            throw range_error("parameters of window is incorrect");
        }
        w_length = win_l;
        w_width = win_w;
    }
    
    WBox(int l, int w, int h, int win_l, int win_w): Box(l, w, h) {
        if (win_l < 0 || win_w < 0) {
            throw range_error("some parameters is negative");
        }
        if (win_l >= l || win_w >= h) {
            throw range_error("parameters of window is incorrect");
        }
        w_length = win_l;
        w_width = win_w;
    }
    
    WBox(const WBox & b) : Box(b) {
        w_length = b.w_length;
        w_width = b.w_width;
    }
    
    virtual ~WBox() {
        cout << "~WBox()" << endl;
    }
    
    int get_wl() const {
        return w_length;
    }
    
    int get_ww() const {
        return w_width;
    }
    
    virtual int area() const {
        return (Box::area() - w_length * w_width);
    }

    virtual string class_name() {
        return "WBox";
    }
    
    virtual void print_content() {
        Box::print_content();
        cout << ", w_length: " << w_length << ", w_width: " << w_width;
    }    
};

/*-------------- CLASS HBOX -------------- */

class HBox: public virtual Box {
private:
    int h_height;
public:
    HBox(): Box() {
        h_height = 0;
    }
    
    HBox(int n): Box() {
        if (n < 0) {
            throw range_error("parameter is negative");
        }
        h_height = n;
    }
    
    HBox(int n, int hh): Box(n) {
        if (hh < 0) {
            throw range_error("parameter is negative");
        }
        if (hh > n) {
            throw range_error("parameter of head is incorrect");
        }
        h_height = hh;
    }
    
    HBox(int l, int h, int hh): Box(l, h) {
        if (hh < 0) {
            throw range_error("parameter is negative");
        }
        if (hh > h) {
            throw range_error("parameter of head is incorrect");
        }
        h_height = hh;
    }
    
    HBox(int l, int w, int h, int hh): Box(l, w, h) {
        if (hh < 0) {
            throw range_error("parameter is negative");
        }
        if (hh > h) {
            throw range_error("parameter of head is incorrect");
        }
        h_height = hh;
    }   
    
    HBox(const HBox & b) : Box(b) {
        h_height = b.h_height;
    }
    
    virtual ~HBox() {
        cout << "~HBox()" << endl;
    }
    
    int get_hh() const {
        return h_height;
    }
    
    virtual int area() const {
        return (Box::area() + get_l() * get_w() + 2 * h_height * get_l() + 2 * get_w() * h_height);
    }
    
    virtual string class_name() {
        return "HBox";
    }
    
    virtual void print_content() {
        Box::print_content();
        cout << ", h_height: " << h_height;
    }
};

/*---------------- CLASS WHBOX ---------------- */

class WHBox: public WBox, public HBox {

public:
    WHBox(): Box(), WBox(), HBox(){
    }
    
    WHBox(int n): Box(n), WBox(), HBox() {
    }
    
    WHBox(int l, int h): Box(l, h), WBox(), HBox() {
    }
    
    WHBox(int n, int win, int hh): Box(n), WBox(win), HBox(hh) {
    }
    
    WHBox(int n, int win_l, int win_w, int hh): Box(n), WBox(win_l, win_w), HBox(hh) {
    }
    
    WHBox(int l, int h, int win_l, int win_w, int hh): Box(l, h), WBox(win_l, win_w), HBox(hh) {
    }  
     
    WHBox(int l, int w, int h, int win_l, int win_w, int hh): Box(l, w, h), WBox(win_l, win_w), HBox(hh) {
    }  
    
    WHBox(const WHBox & b) : Box(b),  WBox(b), HBox(b) {
    }
    
    virtual ~WHBox() {
        cout << "~WHBox()" << endl;
    }
    
    virtual int area() const {
        return (HBox::area() - Box::area() + WBox::area());
    }
    
    virtual string class_name() {
        return "WHBox";
    }
    
    virtual void print_content() {
        Box::print_content();
        cout << ", w_length: " << WBox::get_wl() << ", w_width: " << WBox::get_ww() << ", h_height: " << HBox::get_hh();
    }
};

/*---------------- CLASS STACK ---------------- */

template <class T> class Stack { 
    T* body;
    int size;
    int top; 
public:
    Stack() {
        size = 4;
        top = 0;
        body = new T[4];
        cout << "default constructor stack(size=4) of " << typeid(T).name() << " type elements " << endl;
    }
    
    Stack(int sz) {
        size = sz;
        top = 0;
        body = new T[size]; 
        cout << "constructor stack(size=" << size << ") of " << typeid(T).name() << " type elements " << endl;
    }
    
    Stack(const Stack & st) {
        size = st.size;
        top = st.top;
        body = new T[size];
        for (int i = 0; i < size; i++) {
            body[i] = st.body[i];
        }
        cout << "copy constructor stack(size=" << size << ") of " << typeid(T).name() << " type elements " << endl;
    }
    
    ~Stack() {
        delete[] body;
        cout << "~Stack()" << endl;
    }
    
    void push(T operand) {
        if (top == size) {
            throw out_of_range("stack is full");
        }
        body[top] = operand;
        top++;
        cout << "was pushed: " << operand << endl;
    }
    
    T pop() {
        if (top == 0) {
            throw out_of_range("stack is empty");
        }
        top--;
        cout << "was poped: " << body[top] << endl;
        return body[top];
    }
    
    void print() {
        cout << "stack [";
        for (int i = 0; i < top; i++) {
            cout << body[i];
            if (i < top - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

/*================================ MAIN =============================== */

int main () {
    
    cout << "\n --------------------- TESTING EXCEPTIONS AND ERRORS --------------------- \n" << endl;
    try {
        Box a(-10); /* n= -10 negative size of box */
        cout << "error box was created" << endl;
    } catch (range_error& e) {
        cout << "ERROR " << e.what() << endl;
    }
    
    try {
        WBox b(3, 4, 4); /* n=3 size of box, win=4x4 size of window */
        cout << "error box was created" << endl;
    } catch (range_error& e) {
        cout << "ERROR " << e.what() << endl;
    }
    
    try {
        HBox c(5, 10); /* n=5 size of box, hh=10 size of head */
        cout << "error box was created" << endl;
    } catch (range_error& e) {
        cout << "ERROR " << e.what() << endl;
    }
    
    cout << "\n --------- TESTING BOX-CLASS CONSTRUCTORS, METHODS, AND OPERATIONS -------- \n" << endl;
    Box box1;
    cout << "box1 by default: ";
    box1.print();
    
    box1.set_l(5);
    box1.set_w(6);
    box1.set_h(9); 
    cout << "box1 after setting size (5,6,9): ";
    box1.print();
    
    Box box2(3);
    cout << "box2 by 1-parameter constructor (3): ";
    box2.print();
    
    Box box3(3, 4, 6);
    cout << "box3 by 3-parameter constructor (3,4,6): ";
    box3.print();
    
    Box box4 = box3;
    cout << "box4 by copy constructor (box3): ";
    box4.print();
    
    box2 = box3++;
    cout << "box2 after postfix box3++ : ";
    box2.print();
    
    box4 = --box1;
    cout << "box4 after prefix --box1 : ";
    box4.print();
    
    Box box5 = box1 + box2;
    cout << "box5 after sum box1 + box2: ";
    box5.print();
    
    cout << "\n ---------------- TESTING WBOX-CLASS CONSTRUCTORS, METHODS --------------- \n" << endl;
    WBox box6(6, 7, 8, 2, 3);
    cout << "box6 by WBox-class constructor (6,7,8,2,3): ";
    box6.print();
    
    cout <<  "\n ---------------- TESTING HBOX-CLASS CONSTRUCTORS, METHODS -------------- \n" << endl;
    HBox box7(2, 3, 5, 1);
    cout << "Box7 by HBox-class constructor (2,3,5,1): ";
    box7.print();
    
    cout <<  "\n ---------------- TESTING WHBOX-CLASS CONSTRUCTORS, METHODS -------------- \n" << endl;
    WHBox box8(6, 8, 9, 2, 1, 3);
    cout << "Box8 by WHBox-class constructor (6,8,9,2,1,3): ";
    box8.print();
    
    cout << "\n --------------------- TESTING VIRTUAL FUNCTION AREA -------------------- \n" << endl;
    Body * ptr;
    ptr = &box5;
    cout << "box5 area from (body*-type)pointer: " << ptr->area() << endl;

    ptr = &box6;
    cout << "box6 area from (body*-type)pointer: " << ptr->area() << endl;
    
    ptr = &box7;
    cout << "box7 area from (body*-type)pointer: " << ptr->area() << endl;
    
    
    cout << " \n ------------- TESTING STACK-CLASS CONSTRUCTORS AND METHODS ------------- " << endl;
    cout << " -------------------- ('i' for int, 'd' for double) ---------------------\n " << endl;
    
    Stack <double> stack1;
    Stack <int> stack2(16);
    Stack <int> stack3(stack2);
    
    for (int i = 1; i < 5; i++) {
        stack1.push(i - 0.1);
    }
    stack1.print();
    
    cout << "testing boarder condition (push fifth element to 4-element stack): " << endl;
    try {
        stack1.push(5);
        cout << "something is wrong, pushed to a full stack" << endl;
    } catch (out_of_range) {
        cout << " ---> push to full stack failed as expected" << endl;
    }
    
    for (int i = 1; i < 5; i++) {
        stack1.pop();
    }
    stack1.print(); 
    
    cout << "testing boarder condition (pop element from empty stack): " << endl;
    try {
        stack1.pop();
        cout << "something is wrong, poped from an empty stack" << endl;
    } catch (out_of_range) {
        cout << " ---> pop from empty stack failed as expected" << endl;
    }
    
    cout << "\n ------------------------- TESTING DESTRUCTORS  -------------------------- " << endl; 
    cout << " --------- was created 3 objects of stack class, 1 of WHBox class -------- "<< endl;
    cout << " ----------- 1 of HBox class, 1 of WBox class, 5 of Box class ------------ \n" << endl; 
    return 0;  
}