    bool operator==(const Value& val_1_v) const{
        value_t val_1 = val_1_v.get_value();
        value_t val_2 = value;

        if (std::holds_alternative<long long>(val_1) && std::holds_alternative<long double>(val_2)) {
            return std::get<long long>(val_1) == std::get<long double>(val_2);
        }
        else if (std::holds_alternative<long double>(val_1) && std::holds_alternative<long long>(val_2)) {
            return std::get<long double>(val_1) == std::get<long long>(val_2);
        }

        if (val_1.index() != val_2.index()){
            return false;
        }

        if (std::holds_alternative<long long>(val_1)){
            return std::get<long long>(val_1) == std::get<long long>(val_2);
        }
        else if (std::holds_alternative<long double>(val_1)){
            return std::get<long double>(val_1) == std::get<long double>(val_2);
        }
        else if (std::holds_alternative<bool>(val_1)){
            return std::get<bool>(val_1) == std::get<bool>(val_2);
        }
        else if (std::holds_alternative<std::string>(val_1)){
            return std::get<std::string>(val_1) == std::get<std::string>(val_2);
        }
        else if (std::holds_alternative<std::vector<Value> >(val_1)){
            return std::get<std::vector<Value> >(val_1) == std::get<std::vector<Value> >(val_2);
        }
        else if (std::holds_alternative<none>(val_1)){
            return std::get<none>(val_1) == std::get<none>(val_2);
        }
        return false;
    }
