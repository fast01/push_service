//
//  apns_response.hpp
//  push_service
//
//  Created by Alexander Kremer on 08/07/2013.
//  Copyright (c) 2013 godexsoft. All rights reserved.
//

#ifndef _PUSH_SERVICE_APNS_RESPONSE_HPP_
#define _PUSH_SERVICE_APNS_RESPONSE_HPP_

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <push/apns_errors.hpp>

namespace push {
namespace detail {
        
    class apns_response
    {
    public:
        friend class apns_connection;
        apns_response(boost::asio::streambuf& data);
      
        const boost::system::error_code to_error_code() const;
        
        const push::error::apns_err_code get_status() const;
        
        const uint32_t get_identity() const;
        
    private:
        push::error::apns_err_code  status_;
        uint32_t                    identity_;
    };

    class apns_feedback_response
    {
    public:
        friend class apns_feedback_connection;

        apns_feedback_response(std::string& data);
        
        const boost::posix_time::ptime get_time() const;
        
        const std::string get_token() const;
        
    private:
        boost::posix_time::ptime    time_;
        std::string                 token_;
    };
    
} // namespace detail
} // namespace push

#endif // _PUSH_SERVICE_APNS_RESPONSE_HPP_
