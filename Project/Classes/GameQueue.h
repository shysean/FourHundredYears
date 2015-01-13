//
//  GameQueue.h
//  Project
//
//  Created by 史宏阳 on 1/13/15.
//
//

#ifndef Project_GameQueue_h
#define Project_GameQueue_h

template <class T>
class GameQueue
{
public:
    GameQueue() {}
    GameQueue(const GameQueue& rhs)
    {
        m_data = rhs.m_data;
    }
    
    T& readAndPop()
    {
        m_mutex.lock();
        T& value = m_data.front();
        m_data.pop();
        m_mutex.unlock();

        return value;
    }
    
    void push(const T& data)
    {
        m_mutex.lock();
        m_data.push(data);
        m_mutex.unlock();

    }
    
    bool empty() const
    {
        return m_data.empty();
    }
    
    unsigned int size() const
    {
        return m_data.size();
    }
    
    T& front() { return m_data.front(); }
    const T& front() const { return m_data.front(); }
    
    void pop()
    {
        m_mutex.lock();
        m_data.pop();
        m_mutex.unlock();

    }
    
    void deleteAll()
    {
        m_mutex.lock();
        while (!m_data.empty())
        {
            T& data = m_data.front();
            delete data;
            m_data.pop();
        }
        m_mutex.unlock();
    }
    
private:
    std::queue<T> m_data;
    std::mutex m_mutex;
};

#endif
