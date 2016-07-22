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
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>

int main(int, char**) {
    std::vector<std::string> entries{"2 two", "1 one", "10 ten"};
    std::sort(entries.begin(), entries.end());
    printf("ASCIIbetical sort:\n\n");
    for(const auto &i: entries) {
        printf("%s\n", i.c_str());
    }
    std::sort(entries.begin(), entries.end(), natural_comparator<std::string>);
    printf("\nNatural sort:\n\n");
    for(const auto &i: entries) {
        printf("%s\n", i.c_str());
    }
}