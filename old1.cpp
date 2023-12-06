////
//// chat_server.cpp
//// ~~~~~~~~~~~~~~~
////
//// Copyright (c) 2003-2023 Christopher M. Kohlhoff (chris at kohlhoff dot com)
////
//// Distributed under the Boost Software License, Version 1.0. (See accompanying
//// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////
//
//#include <cstdlib>
//#include <deque>
//#include <iostream>
//#include <list>
//#include <memory>
//#include <set>
//#include <utility>
//#include <chrono>
//#include <boost/asio.hpp>
//#include "chat_message.hpp"
//#include "ZAUtilities.h"
//#include "ZADataFormat.h"
//
//static int iSentMsg = 0;
//static unsigned short serverPortNum1 = 4105;
//static unsigned short serverPortNum2 = 4115;
//static unsigned short serverRoomNum1 = 5;
//static unsigned short serverRoomNum2 = 10;
//static unsigned short serverRoomNumOffset1 = 100;
//static unsigned short serverRoomNumOffset2 = 200;
//static unsigned short roomMaxParticipant = 3;
//static boost::asio::io_context serverBoostChannelOS;
//
//using namespace za::net;
//
////using boost::asio::ip::tcp;
////----------------------------------------------------------------------
//
//typedef std::deque<chat_message> chat_message_queue;
//
////----------------------------------------------------------------------
//
//class chat_participant
//{
//public:
//    virtual ~chat_participant() {}
//    virtual void deliver(const chat_message& msg) = 0;
//    virtual boost::asio::ip::tcp::endpoint& get_participant_id() = 0;
//    virtual boost::asio::ip::tcp::endpoint& get_host_id() = 0;
//
//};
//
//typedef std::shared_ptr<chat_participant> chat_participant_ptr;
//
////----------------------------------------------------------------------
//enum class ROOM_STATE
//{
//    EMPTY,
//    USED,
//    MAX
//};
//class chat_room
//{
//public:
//    chat_room() = delete;
//    chat_room(boost::asio::io_context& io_context, unsigned short chat_room_num) : io_context_(io_context),
//        chat_room_num_(chat_room_num)
//    {
//        chat_room_num_ = chat_room_num;
//        state_ = ROOM_STATE::EMPTY;
//        chat_participant_num_ = 0;
//    }
//    void join(chat_participant_ptr participant)
//    {
//        update_participant_num();
//        participants_.insert(participant);
//        reset_state();
//        //welcome(participant);
//    }
//    void leave(chat_participant_ptr participant)
//    {
//        std::cout << "A client leaves the meeting room" << std::endl;
//        std::cout << "The number of the clients in the meeting was [" << participants_.size() << "]" << std::endl;
//        participants_.erase(participant);
//        --chat_participant_num_;
//        std::cout << "The number of the clients in the meeting is [" << participants_.size() << "]" << std::endl;
//        reset_state();
//    }
//    void deliver(const chat_message& msg)
//    {
//        std::cout << "Delivering a client message content to all the participants in the meeting room" << std::endl;
//        recent_msgs_.push_back(msg);
//        while (recent_msgs_.size() > max_recent_msgs)
//            recent_msgs_.pop_front();
//
//        for (auto participant : participants_)
//            participant->deliver(msg);
//    }
//    unsigned short& get_room_num()
//    {
//        return chat_room_num_;
//    }
//    unsigned short& get_participant_num()
//    {
//        return chat_participant_num_;
//    }
//
//    void update_participant_num()
//    {
//        ++chat_participant_num_;
//    }
//    void welcome(chat_participant_ptr participant)
//    {
//        std::cout << "Client [" << participant->get_participant_id() << "] welcome to room[" << get_room_num() << "], participants[" << get_participant_num() << "]" << std::endl;
//
//
//        char buffer[cnt::ZA_SIZE];
//        buffer[cnt::ZA_PACKET::HEADER_1] = cnt::ZA_HEADER_1::HEADER_1_1;
//        buffer[cnt::ZA_PACKET::HEADER_2] = cnt::ZA_HEADER_2::HEADER_2_1;
//        buffer[cnt::ZA_PACKET::HEADER_3] = cnt::ZA_HEADER_3::HEADER_3_1;
//
//        buffer[cnt::ZA_PACKET::BODY_1] = 'z';
//        buffer[cnt::ZA_PACKET::BODY_2] = 'o';
//        buffer[cnt::ZA_PACKET::BODY_3] = 'u';
//        buffer[cnt::ZA_PACKET::BODY_4] = 'm';
//        buffer[cnt::ZA_PACKET::BODY_5] = 'a';
//
//        chat_message msg;
//        msg.body_length(cnt::ZA_SIZE);
//        std::memcpy(msg.body(), buffer, cnt::ZA_SIZE);
//        msg.encode_header();
//        recent_msgs_.push_back(msg);
//
//        for (const auto& i_msg : recent_msgs_)
//        {
//            participant->deliver(i_msg);
//        }
//    }
//    void reset_state()
//    {
//        ;
//        if (participants_.size() == 0)
//        {
//            set_state(ROOM_STATE::EMPTY);
//        }
//        else if (participants_.size() == roomMaxParticipant)
//        {
//            set_state(ROOM_STATE::MAX);
//        }
//        else
//        {
//            set_state(ROOM_STATE::USED);
//        }
//    }
//    void set_state(ROOM_STATE state)
//    {
//        state_ = state;
//    }
//private:
//    std::set<chat_participant_ptr> participants_;
//    enum { max_recent_msgs = 100 };
//    chat_message_queue recent_msgs_;
//    unsigned short chat_room_num_;
//    unsigned short chat_participant_num_;
//    ROOM_STATE state_;
//    boost::asio::io_context& io_context_;
//};
//
//typedef std::shared_ptr<chat_room> chat_room_ptr;
////----------------------------------------------------------------------
//
//class chat_session
//    : public chat_participant,
//    public std::enable_shared_from_this<chat_session>
//{
//public:
//
//    chat_session(boost::asio::io_context& io_context, boost::asio::ip::tcp::socket socket, chat_room_ptr room)
//        :socket_(std::move(socket)),
//        io_context_(io_context),
//        room_(room)
//    {
//        chat_host_id_ = socket_.local_endpoint();
//        chat_participant_id_ = socket_.remote_endpoint();
//        session_duration_ = std::chrono::seconds(0);
//    }
//
//    void start(std::chrono::seconds session_time)
//    {
//        session_duration_ = session_time;
//        std::cout << "Host ["
//            << get_host_id()
//            << "]starts a session["
//            << get_session_duration()
//            << "sec] with Client["
//            << get_participant_id()
//            << "] in room["
//            << get_room_num() << "]"
//            << std::endl;
//
//        room_->join(shared_from_this());
//
//
//
//        do_read_header();
//        end();
//
//    }
//
//    void deliver(const chat_message& msg)
//    {
//        std::cout << "Start the process of delivering a message to a client" << std::endl;
//        bool write_in_progress = !write_msgs_.empty();
//        /*write_msgs_.push_back(msg);*/
//        if (!write_in_progress)
//        {
//            write_msgs_.push_back(msg);
//            std::cout << "There is a message available to deliver to a client" << std::endl;
//            do_write();
//        }
//        else
//        {
//            std::cout << "There is not a message available to deliver to a client" << std::endl;
//        }
//
//    }
//
//    void end()
//    {
//        boost::asio::post(io_context_,
//            [this]()
//            {
//                boost::asio::high_resolution_timer timer(io_context_);
//                timer.expires_from_now(std::chrono::seconds(session_duration_));
//                timer.wait();
//                room_->leave(shared_from_this());
//                socket_.close();
//            });
//    }
//
//    unsigned short& get_room_num()
//    {
//        return room_->get_room_num();
//    }
//
//    boost::asio::ip::tcp::endpoint& get_host_id()
//    {
//        return chat_host_id_;
//    }
//    boost::asio::ip::tcp::endpoint& get_participant_id()
//    {
//        return chat_participant_id_;
//    }
//    double get_session_duration()
//    {
//        return std::chrono::duration_cast<std::chrono::seconds>(session_duration_).count();
//    }
//
//private:
//    void do_read_header()
//    {
//
//        //std::cout << "Waiting for incoming message from a client" << std::endl;
//        auto self(shared_from_this());
//        boost::asio::async_read(socket_,
//            boost::asio::buffer(read_msg_.data(), chat_message::header_length),
//            [this, self](boost::system::error_code ec, std::size_t /*length*/)
//            {
//                if (!ec && read_msg_.decode_header())
//                {
//
//                    do_read_body();
//
//                }
//                else
//                {
//                    std::cout << "A client header message decoded failed" << std::endl;
//                    std::cout << "Request a client to leave the room" << std::endl;
//                    room_->leave(shared_from_this());
//                }
//            });
//    }
//
//    void do_read_body()
//    {
//        //std::cout << "Start the reading a client message content process" << std::endl;
//        auto self(shared_from_this());
//        boost::asio::async_read(socket_,
//            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
//            [this, self](boost::system::error_code ec, std::size_t /*length*/)
//            {
//                if (!ec)
//                {
//                    //std::cout << "Reading a client message content successfully" << std::endl;
//                    //std::cout << "Deliver a client message content to all the participant including himself" << std::endl;
//                    //char buffer[cnt::ZA_SIZE];
//                    //std::memcpy(buffer, read_msg_.body(), cnt::ZA_SIZE);
//                    //std::cout << "Server gets the message[";
//                    //std::cout.write(read_msg_.body(), cnt::ZA_SIZE);
//                    //std::cout << "] from the client";
//                    //std::cout << std::endl;
//
//                    //room_->deliver(read_msg_);
//
//                    //std::cout << "Keep decoding a client message header before reading its content" << std::endl;
//                    char buffer[cnt::ZA_SIZE];
//                    std::memcpy(buffer, read_msg_.body(), cnt::ZA_SIZE);
//                    std::cout << "Server got the message[";
//                    std::cout.write(read_msg_.body(), cnt::ZA_SIZE);
//                    std::cout << "] from the client";
//                    std::cout << std::endl;
//                    do_read_header();
//                }
//                else
//                {
//                    std::cout << "Reading a client message content failed" << std::endl;
//                    room_->leave(shared_from_this());
//                }
//            });
//    }
//
//    void do_write()
//    {
//        std::cout << "Deliver a message to a client" << std::endl;
//        auto self(shared_from_this());
//        boost::asio::async_write(socket_,
//            boost::asio::buffer(write_msgs_.front().data(),
//                write_msgs_.front().length()),
//            [this, self](boost::system::error_code ec, std::size_t /*length*/)
//            {
//                if (!ec)
//                {
//                    std::cout << "Delivered a message to a client successfully[" << ++iSentMsg << "]" << std::endl;
//                    std::cout << "Message[" << std::string(write_msgs_.front().data(), write_msgs_.front().length()) << "]" << std::endl;
//                    write_msgs_.pop_front();
//                    if (!write_msgs_.empty())
//                    {
//
//                        std::cout << "Keep delivering the remaining messages to a client" << std::endl;
//                        do_write();
//                    }
//                    else
//                    {
//                        std::cout << "Done delivering a message to a client" << std::endl;
//                    }
//                }
//                else
//                {
//                    std::cout << "Delivered a message to a client failed" << std::endl;
//                    std::cout << "Request a client to leave the meeting room" << std::endl;
//                    room_->leave(shared_from_this());
//                }
//            });
//
//    }
//
//    std::chrono::seconds session_duration_;
//    boost::asio::ip::tcp::socket socket_;
//    chat_room_ptr room_;
//    unsigned short chat_room_num_;
//    boost::asio::ip::tcp::endpoint chat_participant_id_;
//    boost::asio::ip::tcp::endpoint chat_host_id_;
//    chat_message read_msg_;
//    chat_message_queue write_msgs_;
//    boost::asio::io_context& io_context_;
//
//};
//
////----------------------------------------------------------------------
//
//class chat_server
//{
//public:
//    chat_server(boost::asio::io_context& io_context,
//        const boost::asio::ip::tcp::endpoint& endpoint, unsigned short room_num, unsigned short room_num_offset)
//        : io_context_(io_context), acceptor_(io_context, endpoint), room_num_(room_num), room_num_offset_(room_num_offset), client_num_(0)
//    {
//        do_room();
//        do_accept();
//    }
//
//private:
//    void do_accept()
//    {
//        std::cout << "Host at reception desk[" << acceptor_.local_endpoint() << "]" << std::endl;
//        acceptor_.async_accept(
//            [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
//            {
//                std::cout << "Client[" << socket.remote_endpoint() << "] at reception desk[" << socket.local_endpoint() << "]" << std::endl;
//
//                if (!ec)
//                {
//                    std::cout << "Client[" << socket.remote_endpoint() << "] at reception desk[" << socket.local_endpoint() << "][OK]" << std::endl;
//                    std::make_shared<chat_session>(io_context_, std::move(socket), room_[client_num_ % room_num_])->start(std::chrono::seconds(100));
//
//                }
//                else
//                {
//                    std::cout << "Client[" << socket.remote_endpoint() << "] at reception desk[" << socket.local_endpoint() << "][NO]" << std::endl;
//                }
//                std::cout << "Server back to reception" << std::endl;
//                do_accept();
//            });
//    }
//    void do_room()
//    {
//        for (unsigned short i_room = 0; i_room < room_num_; i_room++)
//        {
//            room_.emplace_back(std::make_shared<chat_room>(io_context_, i_room + room_num_offset_));
//        }
//    }
//    boost::asio::ip::tcp::acceptor acceptor_;
//    std::vector<chat_room_ptr> room_;
//    unsigned short room_num_;
//    unsigned short client_num_;
//    unsigned short room_num_offset_;
//    boost::asio::io_context& io_context_;
//};
//
////----------------------------------------------------------------------
//
//int main(int argc, char* argv[])
//{
//    try
//    {
//
//        std::list<chat_server> servers;
//
//        boost::asio::ip::tcp::endpoint serverBoostAddress1(boost::asio::ip::tcp::v4(), serverPortNum1);
//        //boost::asio::ip::tcp::endpoint serverBoostAddress2(boost::asio::ip::tcp::v4(), serverPortNum2);
//
//        servers.emplace_back(serverBoostChannelOS, serverBoostAddress1, serverRoomNum1, serverRoomNumOffset1);
//        //servers.emplace_back(serverBoostChannelOS, serverBoostAddress2, serverRoomNum2, serverRoomNumOffset1);
//        serverBoostChannelOS.run();
//    }
//    catch (std::exception& e)
//    {
//        std::cerr << "Exception: " << e.what() << "\n";
//    }
//
//    return 0;
//}
