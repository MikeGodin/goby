// Copyright 2009-2013 Toby Schneider (https://launchpad.net/~tes)
//                     Massachusetts Institute of Technology (2007-)
//                     Woods Hole Oceanographic Institution (2007-)
//                     Goby Developers Team (https://launchpad.net/~goby-dev)
// 
//
// This file is part of the Goby Underwater Autonomy Project Libraries
// ("The Goby Libraries").
//
// The Goby Libraries are free software: you can redistribute them and/or modify
// them under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The Goby Libraries are distributed in the hope that they will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Goby.  If not, see <http://www.gnu.org/licenses/>.


#ifndef LIAISONCONTAINER20130128H
#define LIAISONCONTAINER20130128H

#include <Wt/WContainerWidget>
#include <Wt/WText>

#include "goby/common/protobuf/liaison_config.pb.h"

namespace goby
{
    namespace common
    {
            
        enum 
        {
            LIAISON_INTERNAL_PUBLISH_SOCKET = 1,
            LIAISON_INTERNAL_SUBSCRIBE_SOCKET = 2
//            LIAISON_INTERNAL_COMMANDER_SUBSCRIBE_SOCKET = 3,
//            LIAISON_INTERNAL_COMMANDER_PUBLISH_SOCKET = 4,
//            LIAISON_INTERNAL_SCOPE_SUBSCRIBE_SOCKET = 5,
//            LIAISON_INTERNAL_SCOPE_PUBLISH_SOCKET = 6,  
        };

        
        inline std::string liaison_internal_publish_socket_name() { return "liaison_internal_publish_socket"; }
        inline std::string liaison_internal_subscribe_socket_name() { return "liaison_internal_subscribe_socket"; }
        
        class LiaisonContainer : public  Wt::WContainerWidget
        {
          public:
          LiaisonContainer(Wt::WContainerWidget* parent)
              : Wt::WContainerWidget(parent)
            {
                setStyleClass("fill");
                /* addWidget(new Wt::WText("<hr/>")); */
                /* addWidget(name_); */
                /* addWidget(new Wt::WText("<hr/>")); */
            }
            
            virtual ~LiaisonContainer()
            { cleanup(); }            
            
            void set_name(const Wt::WString& name)
            {
                name_.setText(name);
            }

            const Wt::WString& name() { return name_.text(); }
            
            virtual void focus() { }
            virtual void unfocus() { }
            virtual void cleanup() { }            

            
          private:
            Wt::WText name_;
        };        

    }
}
#endif