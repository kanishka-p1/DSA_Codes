
/*************
 Driver program to test below functions
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
****************/

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    // Complete the class
    
    Polynomial() {
        degCoeff = new int[10];
        for(int i = 0; i < 10; i++) {
            degCoeff[i] = 0;
        }
        capacity = 10;
    }
    
    Polynomial(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
    }
    
    void print() const {
        for(int i = 0; i < capacity; i++) {
            if(degCoeff[i]) {
                cout << degCoeff[i] << "x" <<i << " ";
            }
            cout << endl;
        }
    }
    
    void setCoefficient(int d, int element) {
        if(d >= capacity) {
            int size = d + 1;
            int *newp = new int[size];
            for(int i = 0; i < capacity; i++) {
                newp[i] = degCoeff[i];
            }
            for(int i = capacity; i < size; i++) {
                newp[i] = 0;
            }
            delete [] degCoeff;
            degCoeff = newp;
            capacity = size;
        }
        degCoeff[d] = element;
    }
    
    Polynomial operator+(Polynomial const &p) {
        Polynomial newp;
        newp.capacity = max(capacity, p.capacity);
        newp.degCoeff = new int[newp.capacity];
        
        if(capacity < p.capacity) {
            int i;
            for(i = 0; i < capacity; i++) {
                newp.degCoeff[i] = degCoeff[i] + p.degCoeff[i];
            }
            for(; i < p.capacity; i++) {
                newp.degCoeff[i] = p.degCoeff[i];
            }
        }
        else {
            int i;
            for(i = 0; i < p.capacity; i++) {
                newp.degCoeff[i] = degCoeff[i] + p.degCoeff[i];
            }
            for(; i < capacity; i++) {
                newp.degCoeff[i] = degCoeff[i];
            }
        }
        return newp;
    }
    
    Polynomial operator-(Polynomial const &p) {
        Polynomial newp;
        newp.capacity = max(capacity, p.capacity);
        newp.degCoeff = new int[newp.capacity];
        
        if(capacity < p.capacity) {
             int i;
            for(i = 0; i < capacity; i++) {
                newp.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            }
            for(; i < p.capacity; i++) {
                newp.degCoeff[i] = -p.degCoeff[i];
            }
        }
        else {
             int i;
            for(i = 0; i < capacity; i++) {
                newp.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            }
            for(; i < p.capacity; i++) {
                newp.degCoeff[i] = p.degCoeff[i];
            }
        }
        return newp;
    }
    
    Polynomial operator*(Polynomial const &p) {
        Polynomial newp;
        newp.capacity = max(capacity, p.capacity);
        newp.degCoeff = new int[newp.capacity];
        
        for(int i = 0; i < newp.capacity; i++) {
            newp.degCoeff[i] = 0;
        }
        
        for(int i = 0; i < capacity; i++) {
            for(int j = 0; j < p.capacity; j++) {
                newp.degCoeff[i + j] += degCoeff[i] * p.degCoeff[j];
            }
        }
    }
    
    Polynomial operator=(Polynomial const &p) {
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++) {
            this -> degCoeff[i] = p.degCoeff[i];
        }
        this -> capacity = p.capacity;
        return *this;
    }
    
};
