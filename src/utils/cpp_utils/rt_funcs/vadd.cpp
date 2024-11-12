    static Value vadd(const Value& val_1_v, const Value& val_2_v) {
        value_t val_1 = val_1_v.get_value();
        value_t val_2 = val_2_v.get_value();

        if (std::holds_alternative<int>(val_1) && std::holds_alternative<int>(val_2)) {
            int raw_res = std::get<int>(val_1) + std::get<int>(val_2);
            return Value(raw_res);
        }
        else if (std::holds_alternative<int>(val_1) && std::holds_alternative<float>(val_2)) {
            float raw_res = std::get<int>(val_1) + std::get<float>(val_2);
            return Value(raw_res);
        }
        else if (std::holds_alternative<float>(val_1) && std::holds_alternative<int>(val_2)) {
            float raw_res = std::get<float>(val_1) + std::get<int>(val_2);
            return Value(raw_res);
        }
        else if (std::holds_alternative<float>(val_1) && std::holds_alternative<float>(val_2)) {
            float raw_res = std::get<float>(val_1) + std::get<float>(val_2);
            return Value(raw_res);
        }
        else if (std::holds_alternative<std::string>(val_1) && std::holds_alternative<std::string>(val_2)) {
            std::string raw_res = std::get<std::string>(val_1) + std::get<std::string>(val_2);
            return Value(raw_res);
        }
        else if (std::holds_alternative<std::vector<Value> >(val_1) && std::holds_alternative<std::vector<Value> >(val_2)) {
            std::vector<Value> val_1_vec = std::get<std::vector<Value> >(val_1);
            std::vector<Value> val_2_vec = std::get<std::vector<Value> >(val_2);
            val_1_vec.insert(val_1_vec.end(), val_2_vec.begin(), val_2_vec.end());
            return Value(val_1_vec);
        }
        else {
            RunTime instance;
            instance.throw_rt_error("Invalid type for operation: 'add'");
            return Value(none{});
        }
    }
