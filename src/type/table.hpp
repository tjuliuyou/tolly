#ifndef TERNICE_TOLLY_TABLE_HPP_
#define TERNICE_TOLLY_TABLE_HPP_

/*********1********2********3********4********5********6********7********
**
**  Project:
**
**  Author:  Sven Liu
**  Email:   tjuliuyou@gmail.com
**  Date:
**  Comments:
**
*------------------------------------------------------------------------
************************************************************************/
#include <vector>
#include <string>
#include <cassert>
namespace tolly
{

template<typename T>
class Table
{
public:
  typedef std::vector<T> Row;
  typedef std::vector<Row> TableType;
  Table():rowIndex_(-1){ }
  Table(const Table &from):table_(from.table_),rowIndex_(from.rowindex_){}
  ~Table(){}
  const Table &operator=(const Table& from)
  {
    table_ = from.table_;
    rowIndex_ = from.rowIndex_;
    return *this;
  }

  int fieldCount() const
  {
    if(!table_.empty())
      return table_[0].size();
    return 0;
  }
  int rowCount() const
  {
    return table_.size();
  }

  bool fetchRow()
  {
    if(table_.empty()) return false;
    if(++rowIndex_ >= table_.size()) return false;
    else return true;
  }

  const T &operator[](const int index) const
  {
    assert(rowIndex_ < table_.size());
    assert(index < table_[rowIndex_].size());
    return table_[rowIndex_][index];
  }

  operator bool() const
  {
    return !table_.empty();
  }

  Row* addRow()
  {
    Row row;
    table_.push_back(row);
    return &table_[table_.size()-1];
  }

  void clear(){table_.clear();}

  bool empty() const
  {
    return table_.empty();
  }
private:
  TableType table_;
  int rowIndex_;

} ;

}//tolly


#endif // TERNICE_TOLLY_TABLE_HPP_
