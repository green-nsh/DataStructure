#include <string>
#include <vector>

//tcp消息处理
class TcpMessageHandle {
public:
    TcpMessageHandle() :
        m_sep_1(';'),
        m_sep_2(','),
        m_ecsape('$') { }

    //接收到一条信息, 每接收到一条信息调用一次
    void Recieve(const std::string& data) {
        m_cache += data;
    }

    //获取信息, 需要获取消息时调用, 返回消息列表
    std::vector<std::vector<std::string>> GetMessageList() {
        unsigned int i = 0;
        unsigned int success_pos = 0;
        std::string param;
        std::vector<std::string> message;
        std::vector<std::vector<std::string>> message_list;
        while (i < m_cache.size()) {
            if (m_cache[i] == m_sep_2) {
                message.push_back(param);
                param.clear();
            }
            else if (m_cache[i] == m_sep_1) {
                message.push_back(param);
                message_list.push_back(message);
                param.clear();
                message.clear();
                success_pos = i + 1;
            }
            else if (m_cache[i] == m_ecsape) {
                i++;
                if (i < m_cache.size()) {
                    param.push_back(m_cache[i]);
                }
            }
            else {
                param.push_back(m_cache[i]);
            }
            i++;
        }
        m_cache = m_cache.substr(success_pos);
        return message_list;
    }

    //创建一条消息, 内部自动添加转义符
    std::string CreateMessage(std::vector<std::string> message) {
        std::string output;
        for (std::string& i : message) {
            for (unsigned int j = 0; j < i.size(); j++) {
                if (i[j] == m_sep_1 || i[j] == m_sep_2 || i[j] == m_ecsape) {
                    i.insert(j, 1, m_ecsape);
                    j++;
                }
            }
            output += i + m_sep_2;
        }
        output.back() = m_sep_1;
        return output;
    }

private:
    char m_sep_1;           //指令分隔符
    char m_sep_2;           //参数分隔符
    char m_ecsape;          //转义符
    std::string m_cache;    //数据缓冲区
};
