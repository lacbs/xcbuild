/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __plist_Format_Base_h
#define __plist_Format_Base_h

#include <plist/Base.h>
#include <plist/Object.h>
#include <plist/Format/Type.h>

namespace plist {
namespace Format {

template<typename T>
class Base {
public:
    static Type Type();

public:
    static std::unique_ptr<T>
    Identify(std::vector<uint8_t> const &contents);

public:
    static std::pair<Object *, std::string>
    Deserialize(std::vector<uint8_t> const &contents, T const &format);

public:
    static std::pair<std::unique_ptr<std::vector<uint8_t>>, std::string>
    Serialize(Object *object, T const &format);
};

}
}

#endif  // !__plist_Format_Base_h