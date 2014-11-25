
#ifndef NAMESPACE
#include <list>
#include <map>
#endif

class LRUCache{
    typedef std::pair<int, std::list<int>::iterator> record;

    std::list<int> order_;
    std::map<int, record> kv_;
    int capacity_;

    void refreshKey(int key)
    {
        std::map<int, record>::iterator it = kv_.find(key);

        order_.erase(it->second.second);
        order_.push_back(key);

        std::list<int>::iterator lend = order_.end();
        it->second.second = --lend;
    }
public:
    LRUCache(int capacity) {
        capacity_ = capacity < 0 ? 0 : capacity;
    }
    
    int get(int key) {
        std::map<int, record>::iterator it = kv_.find(key);
        if(it != kv_.end()){
            refreshKey(key);

            return kv_.at(key).first;
        }
        else{
            return -1;
        }
        return kv_.find(key) != kv_.end() ? kv_.at(key).first : -1;
    }
    
    void set(int key, int value) {
        std::map<int, record>::iterator it = kv_.find(key);
        
        if(it == kv_.end()){
            order_.push_back(key);
			std::list<int>::iterator lend = order_.end();
            kv_[key] = std::make_pair(value, --lend);

            //
            if(order_.size() > (size_t)capacity_){
                kv_.erase(order_.front());
                order_.erase(order_.begin());
            }
        }
        else{
            refreshKey(key);
            it->second.first = value;
        }
    }
};
