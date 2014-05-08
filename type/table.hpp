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
namespace tolly
{

template<typename T>
class Table
{
public:
  typedef std::vector<T> Row;
  typedef std::vector<Row> TableType;
  Table():rowIndex_(-1){ }
  Table(const Table &from):table_(from.table_),rowIndex(from.rowindex_){}
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
private:
  TableType table_;
  int rowIndex_;

} ;

}//tolly


#endif // TERNICE_TOLLY_TABLE_HPP_
