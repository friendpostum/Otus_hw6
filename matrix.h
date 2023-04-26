#pragma once

#include <map>
#include <memory>

template<typename T, T defaultVal>
struct Matrix {
private:
    using coordinates = std::pair<std::size_t, std::size_t>;
    using container = std::map<coordinates, T>;

    struct holder {
        holder(container &data, coordinates coord) : data(data),
                                                     coord(std::move(coord)) {};

        operator T() {
            if(data.count(coord)) {
                return data[coord];
            } else {
                return defaultVal;
            }
        }

        holder &operator=(T element) {
            if(element != defaultVal)
                data[coord] = element;
            else
                data.erase(coord);
            return *this;
        };
    private:
        std::pair<std::size_t, std::size_t> coord;
        container &data;
    };

    struct row {
        row(container &data, std::size_t rowindex) : data(data), rowindex(rowindex) {}

        holder operator[](std::size_t colindex) {
            coordinates coord(rowindex, colindex);
            return holder(data, coord);
        }

    private:
        std::size_t rowindex;
        container &data;
    };

public:
    row operator[](std::size_t rowindex) {
        return row(data, rowindex);
    }

    std::size_t size() { return data.size(); };

    class iterator : public std::iterator<std::forward_iterator_tag, T> {
    public:
        iterator(typename container::iterator iter) : it(iter) {};

        bool operator!=(iterator &rhs) { return it != rhs.it; }


        iterator &operator++() {
            ++it;
            return *this;
        }

        std::tuple<std::size_t, std::size_t, T> operator*() {
            return {it->first.first, it->first.second, it->second};
        }

    protected:
        typename container::iterator it;
    };

    iterator begin() { return data.begin(); };

    iterator end() { return data.end(); };

private:
    container data;
};

