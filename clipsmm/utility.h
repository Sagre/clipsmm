/***************************************************************************
 *   clipsmm C++ wrapper for the CLIPS c library                           *
 *   Copyright (C) 2006 by Rick L. Vinyard, Jr.                            *
 *   rvinyard@cs.nmsu.edu                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of version 2 of the GNU General Public License as  *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/
#ifndef CLIPSUTILITY_H
#define CLIPSUTILITY_H

#include <vector>
#include <string>
#include <stdexcept>

extern "C" {
  struct dataObject;
}

namespace CLIPS {

  std::vector<std::string> data_object_to_strings(dataObject* clipsdo);
  std::vector<std::string> data_object_to_strings(dataObject& clipsdo);

  void get_argument(void* env, int argposition, double& value);
  void get_argument(void* env, int argposition, float& value);
  void get_argument(void* env, int argposition, short& value);
  void get_argument(void* env, int argposition, short unsigned& value);
  void get_argument(void* env, int argposition, int& value);
  void get_argument(void* env, int argposition, unsigned& value);
  void get_argument(void* env, int argposition, long& value);
  void get_argument(void* env, int argposition, std::string& value);

  template <typename T_return> inline char get_return_code() {
    throw std::logic_error("clipsmm: Adding function with invalid return type");
  }
  template <> inline char get_return_code<bool>()        { return 'b'; }
  template <> inline char get_return_code<char>()        { return 'c'; }
  template <> inline char get_return_code<double>()      { return 'd'; }
  template <> inline char get_return_code<float>()       { return 'f'; }
  template <> inline char get_return_code<int>()         { return 'i'; }
  template <> inline char get_return_code<long>()        { return 'l'; }
  template <> inline char get_return_code<std::string>() { return 's'; }
  template <> inline char get_return_code<void>()        { return 'v'; }

  template <typename T_return> inline char get_argument_code() {
    throw std::logic_error("clipsmm: Adding function with invalid argument type");
  }
  template <> inline char get_argument_code<double>()      { return 'd'; }
  template <> inline char get_argument_code<float>()       { return 'f'; }
  template <> inline char get_argument_code<int>()         { return 'i'; }
  template <> inline char get_argument_code<long>()        { return 'l'; }
  template <> inline char get_argument_code<std::string>() { return 's'; }


}

#endif