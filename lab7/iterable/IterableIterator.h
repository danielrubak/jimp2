#ifndef JIMP2_ITERABLEITERATOR_H
#define JIMP2_ITERABLEITERATOR_H

#include <utility>
#include <string>
#include <vector>
#include <memory>

namespace utility {
    class IterableIterator {
    public:
        virtual std::pair<int, std::string> Dereference() const = 0;
        virtual IterableIterator &Next() = 0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const = 0;
        virtual ~IterableIterator() = default;
        std::vector<int>::const_iterator left_vec_pos;
        std::vector<int>::const_iterator left_vec_end;
        std::vector<std::string>::const_iterator right_vec_pos;
        std::vector<std::string>::const_iterator right_vec_end;
    };

    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;
    };

    class EnumerateIterator : public IterableIterator {
    public:
        explicit EnumerateIterator(std::vector<std::string>::const_iterator right_start,
                                   std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;
    private:
        int number;
    };

    class ProductIterator : public IterableIterator {
    public:
        explicit ProductIterator(std::vector<int>::const_iterator left,
                                 std::vector<std::string>::const_iterator right,
                                 std::vector<int>::const_iterator left_end,
                                 std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;
    private:
        std::vector<std::string>::const_iterator right_vec_first_elem;
    };
};

#endif //JIMP2_ITERABLEITERATOR_H
