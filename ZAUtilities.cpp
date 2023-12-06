#include "ZAUtilities.h"


namespace za
{
    namespace net
    {
        //void testJson()
        //{
        //    // create an array using push_back
        //    json j;
        //    j.push_back("foo");
        //    j.push_back(1);
        //    j.push_back(true);
        //    // also use emplace_back
        //    j.emplace_back(1.78);

        //    // iterate the array
        //    for (json::iterator it = j.begin(); it != j.end(); ++it)
        //    {
        //        std::cout << *it << '\n';
        //    }
        //    // range-based for
        //    for (auto& element : j) {
        //        std::cout << element << '\n';
        //    }
        //    // getter/setter
        //    const auto tmp = j[0].template get<std::string>();
        //    j[1] = 42;
        //    bool foo = j.at(2);

        //    // comparison
        //    j == R"(["foo", 1, true, 1.78])"_json ? std::cout << "\ntrue\n" : std::cout << "\nfalse\n";  // true

        //    // other stuff
        //    std::cout << "Size: " << j.size() << std::endl;
        //    std::cout << "Empty: " << (j.empty() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "Json type: [";

        //    switch (j.type())
        //    {

        //    case nlohmann::detail::value_t::null:
        //        std::cout << "null";
        //        break;
        //    case nlohmann::detail::value_t::object:
        //        std::cout << "object";
        //        break;
        //    case nlohmann::detail::value_t::array:
        //        std::cout << "array";
        //        break;
        //    case nlohmann::detail::value_t::string:
        //        std::cout << "string";
        //        break;
        //    case nlohmann::detail::value_t::boolean:
        //        std::cout << "boolean";
        //        break;
        //    case nlohmann::detail::value_t::number_integer:
        //        std::cout << "number_integer";
        //        break;
        //    case nlohmann::detail::value_t::number_unsigned:
        //        std::cout << "number_unsigned";
        //        break;
        //    case nlohmann::detail::value_t::number_float:
        //        std::cout << "number_float";
        //        break;
        //    case nlohmann::detail::value_t::binary:
        //        std::cout << "binary";
        //        break;
        //    case nlohmann::detail::value_t::discarded:
        //        std::cout << "discarded";
        //        break;

        //    default:
        //        break;
        //    }


        //    std::cout << "]" << std::endl;
        //    j.clear();    // the array is empty again   
        //    std::cout << "Clear array size: " << j.size() << std::endl;

        //    // convenience type checkers
        //    std::cout << "is_null: " << (j.is_null() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "is_boolean: " << (j.is_boolean() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "is_number: " << (j.is_number() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "is_object: " << (j.is_object() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "is_array: " << (j.is_array() ? "true\n" : "false\n") << std::endl;
        //    std::cout << "is_string: " << (j.is_string() ? "true\n" : "false\n") << std::endl;
        //    // create an object

        //    json o;
        //    o["foo"] = 23;
        //    o["bar"] = false;
        //    o["baz"] = 3.141;
        //    // also use emplace
        //    o.emplace("weather", "sunny");
        //    // special iterator member functions for objects
        //    for (json::iterator it = o.begin(); it != o.end(); ++it)
        //    {
        //        std::cout << it.key() << " : " << it.value() << "\n";
        //    }

        //    // the same code as range for
        //    for (auto& el : o.items())
        //    {
        //        std::cout << el.key() << " : " << el.value() << "\n";
        //    }

        //    // even easier with structured bindings (C++17)
        //    for (auto& [key, value] : o.items())
        //    {
        //        std::cout << key << " : " << value << "\n";
        //    }

        //    // find an entry
        //    if (o.contains("foo"))
        //    {
        //        std::cout << "\nthere is an entry with key \"foo\"\n";
        //        // there is an entry with key "foo"
        //    }
        //    else
        //    {
        //        std::cout << "\nthere isn't an entry with key \"foo\"\n";
        //    }
        //    // or via find and an iterator
        //    if (o.find("foo") != o.end())
        //    {
        //        std::cout << "\nthere is an entry with key \"foo\"\n";
        //        // there is an entry with key "foo"
        //    }
        //    else
        //    {
        //        std::cout << "\nthere isn't an entry with key \"foo\"\n";
        //    }

        //    // or simpler using count()
        //    int foo_present = o.count("foo"); // 1
        //    if (foo_present > 0)
        //    {
        //        std::cout << "\nthere is an entry with key \"foo\"\n";
        //    }
        //    else
        //    {
        //        std::cout << "\nthere isn't an entry with key \"foo\"\n";
        //    }
        //    int fob_present = o.count("fob"); // 0
        //    if (fob_present > 0)
        //    {
        //        std::cout << "\nthere is an entry with key \"fob\"\n";
        //    }
        //    else
        //    {
        //        std::cout << "\nthere isn't an entry with key \"fob\"\n";
        //    }

        //    // delete an entry
        //    o.erase("foo");
        //    std::cout << "\ndelete the entry \"foo\"\n";
        //    if (o.contains("foo"))
        //    {
        //        std::cout << "\nthere is an entry with key \"foo\"\n";
        //        // there is an entry with key "foo"
        //    }
        //    else
        //    {
        //        std::cout << "\nthere isn't an entry with key \"foo\"\n";
        //    }


        //    std::cout << "Conversion from STL containers" << std::endl;
        //    std::cout << "Sequence container" << std::endl;
        //    std::vector<int> c_vector{ 1, 2, 3, 4 };
        //    json j_vec(c_vector);
        //    // [1, 2, 3, 4]
        //    std::cout << "1. vector" << std::endl;
        //    std::cout << j_vec << std::endl;
        //    std::deque<double> c_deque{ 1.2, 2.3, 3.4, 5.6 };
        //    json j_deque(c_deque);
        //    // [1.2, 2.3, 3.4, 5.6]
        //    std::cout << "2. deque" << std::endl;
        //    std::cout << j_deque << std::endl;
        //    std::list<bool> c_list{ true, true, false, true };
        //    json j_list(c_list);
        //    // [true, true, false, true]
        //    std::cout << "3. list" << std::endl;
        //    std::cout << j_list << std::endl;
        //    std::forward_list<int64_t> c_flist{ 12345678909876, 23456789098765, 34567890987654, 45678909876543 };
        //    json j_flist(c_flist);
        //    // [12345678909876, 23456789098765, 34567890987654, 45678909876543]
        //    std::cout << "4. forward list" << std::endl;
        //    std::cout << j_flist << std::endl;
        //    std::array<unsigned long, 4> c_array{ {1, 2, 3, 4} };
        //    json j_array(c_array);
        //    // [1, 2, 3, 4]
        //    std::cout << "5. array" << std::endl;
        //    std::cout << j_array << std::endl;
        //    std::set<std::string> c_set{ "one", "two", "three", "four", "one" };
        //    json j_set(c_set); // only one entry for "one" is used
        //    // ["four", "one", "three", "two"]
        //    std::cout << "6. set" << std::endl;
        //    std::cout << j_set << std::endl;
        //    std::unordered_set<std::string> c_uset{ "one", "two", "three", "four", "one" };
        //    json j_uset(c_uset); // only one entry for "one" is used
        //    // maybe ["two", "three", "four", "one"]
        //    std::cout << "7. unordered set" << std::endl;
        //    std::cout << j_uset << std::endl;
        //    std::multiset<std::string> c_mset{ "one", "two", "one", "four" };
        //    json j_mset(c_mset); // both entries for "one" are used
        //    // maybe ["one", "two", "one", "four"]
        //    std::cout << "8. multiset" << std::endl;
        //    std::cout << j_mset << std::endl;
        //    std::unordered_multiset<std::string> c_umset{ "one", "two", "one", "four" };
        //    json j_umset(c_umset); // both entries for "one" are used
        //    // maybe ["one", "two", "one", "four"]
        //    std::cout << "9. unordered multiset" << std::endl;
        //    std::cout << j_umset << std::endl;


        //    std::cout << "Associative key-value container" << std::endl;
        //    std::map<std::string, int> c_map{ {"one", 1}, {"two", 2}, {"three", 3} };
        //    json j_map(c_map);
        //    // {"one": 1, "three": 3, "two": 2 }
        //    std::cout << "1. map" << std::endl;
        //    std::cout << j_map << std::endl;


        //    std::unordered_map<const char*, double> c_umap{ {"one", 1.2}, {"two", 2.3}, {"three", 3.4} };
        //    json j_umap(c_umap);
        //    // {"one": 1.2, "two": 2.3, "three": 3.4}
        //    std::cout << "2. unordered map" << std::endl;
        //    std::cout << j_umap << std::endl;

        //    std::multimap<std::string, bool> c_mmap{ {"one", true}, {"two", true}, {"three", false}, {"three", true} };
        //    json j_mmap(c_mmap); // only one entry for key "three" is used
        //    // maybe {"one": true, "two": true, "three": true}
        //    std::cout << "3. multimap" << std::endl;
        //    std::cout << j_mmap << std::endl;

        //    std::unordered_multimap<std::string, bool> c_ummap{ {"one", true}, {"two", true}, {"three", false}, {"three", true} };
        //    json j_ummap(c_ummap); // only one entry for key "three" is used
        //    // maybe {"one": true, "two": true, "three": true}
        //    std::cout << "4. unordered multimap" << std::endl;
        //    std::cout << j_ummap << std::endl;

        //    std::cout << "JSON Pointer and JSON Patch" << std::endl;
        //    // a JSON value
        //    json j_original = R"({
        //        "baz": ["one", "two", "three"],
        //        "foo": "bar"
        //        })"_json;

        //    // access members with a JSON pointer (RFC 6901)
        //    //j_original["/baz/1"_json_pointer];
        //    // "two"
        //    std::cout << "access members with a JSON pointer: ";
        //    std::cout << j_original["/baz/1"_json_pointer] << std::endl;
        //    // a JSON patch (RFC 6902)
        //    json j_patch = R"([
        //        { 
        //            "op": "replace", 
        //            "path": "/baz", 
        //            "value": "boo" 
        //        },
        //        { 
        //            "op": "add", 
        //            "path": "/hello", 
        //            "value": ["world"] 
        //        },
        //        { 
        //            "op": "remove", 
        //            "path": "/foo"}
        //        ])"_json;

        //    // apply the patch
        //    json j_result = j_original.patch(j_patch);
        //    std::cout << "apply the patch: ";
        //    std::cout << j_result << std::endl;


        //    // calculate a JSON patch from two JSON values
        //    //json::diff(j_result, j_original);
        //    // [
        //    //   { "op":" replace", "path": "/baz", "value": ["one", "two", "three"] },
        //    //   { "op": "remove","path": "/hello" },
        //    //   { "op": "add", "path": "/foo", "value": "bar" }
        //    // ]
        //    std::cout << "calculate a JSON patch from two JSON values: ";
        //    std::cout << json::diff(j_result, j_original) << std::endl;
        //}

        //void testFFMPEG()
        //{
        //    //unsigned codecVer = avcodec_version();
        //    //int ver_major, ver_minor, ver_micro;
        //    //ver_major = (codecVer >> 16) & 0xff;
        //    //ver_minor = (codecVer >> 8) & 0xff;
        //    //ver_micro = (codecVer) & 0xff;
        //    //printf("FFmpeg version is: %s .\navcodec version is: %d=%d.%d.%d.\n", FFMPEG_VERSION, codecVer, ver_major, ver_minor, ver_micro);

        //}
    }
}