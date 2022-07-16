#include<iostream>
using namespace std;

const int MAX_N = 5e4 + 4;


template <typename T>

class priority_queue{
// private: variable which used in class
private:
    int cnt;    // number of elements in priority_queue
    T heap[MAX_N];
    
    
public:
    int size(){
        return cnt;
    }
    
    // __init__
    priority_queue(){
        cnt = 0;
    }
    
    void swap(int aIdx, int bIdx){
        int temp = heap[aIdx];
        heap[aIdx] = heap[bIdx];
        heap[bIdx] = temp;
    }
    
    void push(T item){
        heap[++cnt] = item;
        int cur = cnt;
        
        for(int i=1; i< cur+1 ; ++i)
            cout << heap[i] << " ";
        
        cout << "\ncur: " << cur << "\n";
        
        while(cur > 1){
            int par = cur >> 1;
            cout << "par: " << par <<"\n";
            // 2번 조건
            if(heap[cur] < heap[par]) break;
            
            swap(cur, par);
            cur = par;
        }
        cout <<"======\n";
    }
    
    void pop(){
        // move the lowest data and delete
        heap[1] = heap[cnt--];
        
        int cur = 1;
        
        while(cur <= cnt){
            int left =(cur << 1) <= cnt ? (cur << 1) : -1;
            int right = (cur << 1 | 1) <= cnt ? (cur << 1 | 1): -1;
            int child = cur; // the index of the largest value is chile
            
            // cur node is leaf node
            if(left == 1) break;
            
            if(heap[cur] < heap[left]){
                child = left;
            }
            
            if(right != -1 && heap[child] < heap[right]){
                child = right;
            }
            
            if(child == left){
                swap(cur, left);
                cur = left;
            }
            
            else if(child == right){
                swap(cur, right);
                cur = right;
            }
            
            // cur == child
            else{
                break;
            }
        }
    }
    
    T top(){
        return heap[1];
    }
    
    bool empty(){
        return cnt == 0 ;
    }
};

int main()
{
    priority_queue<int> pq;
    
    pq.push(17);
    pq.push(5);
    pq.push(10);
    pq.push(19);
    pq.push(21);
    pq.push(8);
    
    int sz = pq.size();
    cout << "size of priority queue: "<< sz <<"\n";
    
    while(!pq.empty()){
        cout <<s pq.top() <<" ";
        pq.pop();
    }
    
    return 0;
}
