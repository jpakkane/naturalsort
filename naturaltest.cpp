/*
 Copyright 2016 Jussi Pakkanen

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include<naturalorder.h>
#include<stdexcept>
#include<cstring>
#include<cstdio>

struct testcase {
    const char *str1;
    const char *str2;
    int expected;
};

const testcase testcases[] = {
        {"a", "b", -1},
        {"b", "a", 1},
        {"a", "a", 0},
        {"a", "", 1},
        {"", "a", -1},
        {"1", "", 1},
        {"", "1", -1},
        {"10", "2", 1},
        {"2", "10", -1},
        {"01", "1", 0},
        {"01a", "1a", 0},
        {"01a", "1b", -1},
        {"01b", "1a", 1},
        {"10 ten", "2 two", 1},
        {"foo1", "foo2", -1},
        {"foo2", "foo1", 1},
        {"a10b20c30", "a10b20c31", -1},
        {"a10b20c31", "a10b20c30", 1},
        {"10", "10", 0},
        {"10a", "10a", 0},
        {"a10", "a10", 0},
};

void check_result(int result, int expected, const testcase &i) {
    if(result != expected) {
        std::string msg("Test failure: \"");
        msg += i.str1;
        msg += "\", \"";
        msg += i.str2;
        msg += "\" order is ";
        msg += std::to_string(result);
        msg += " expected ";
        msg += std::to_string(expected);
        msg += ".";
        throw std::logic_error(msg);
    }

}

void run_test() {
    for(const auto &i: testcases) {
        const char *s1b = i.str1;
        const char *s1e = i.str1 + strlen(i.str1);
        const char *s2b = i.str2;
        const char *s2e = i.str2 + strlen(i.str2);
        int expected = i.expected;
        int char_result = natural_compare(s1b, s1e, s2b, s2e);
        check_result(char_result, expected, i);
        std::string s1(i.str1);
        std::string s2(i.str2);
        int str_result = natural_compare(s1, s2);
        check_result(str_result, expected, i);
    }
}

int main(int argc, char **argv) {
    try {
        run_test();
    } catch(const std::logic_error &e) {
        printf("%s\n", e.what());
        return 1;
    }
    return 0;
}
