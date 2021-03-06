#pragma once

#include "TreeSet.h"
#include "Map.h"

class TreeMapNode : public TreeSetNode, public AbstractEntry {
private:
  void *m_value;
public:
  const void *key() const {
    return TreeSetNode::key();
  }
  void *value() {
    return m_value;
  }
  const void *value() const {
    return m_value;
  }
  friend class TreeMapImpl;
};

class TreeMapImpl : public TreeSetImpl, public AbstractMap {
private:
  AbstractObjectManager *m_dataManager;
protected:
  TreeSetNode         *allocateNode()                                 const override;
  virtual TreeSetNode *createNode(const void *key, const void *value) const;
  TreeSetNode         *cloneNode(TreeSetNode *n)                      const override;
  void                 deleteNode(TreeSetNode *n)                     const override;
  void                 swapContent(TreeSetNode *n1, TreeSetNode *n2)        override;
public:
  TreeMapImpl(const AbstractObjectManager &keyManager, const AbstractObjectManager &dataManager, const AbstractComparator &comparator);
  virtual ~TreeMapImpl()                                       override;
  bool put(       const void *key,       void *value)          override;
  bool put(       const void *key, const void *value)          override;
  bool remove(    const void *key)                             override;
  void *get(      const void *key)                             override;
  const void *get(const void *key)                       const override;
  AbstractEntry *selectEntry(RandomGenerator &rnd)       const override;
  const AbstractEntry *getMinEntry()                     const;
  const AbstractEntry *getMaxEntry()                     const;
  size_t size()                                          const override {
    return TreeSetImpl::size();
  }
  void clear()                                                 override {
    TreeSetImpl::clear();
  }
  bool hasOrder()                                        const override {
    return TreeSetImpl::hasOrder();
  }
  AbstractComparator *getComparator()                          override {
    return TreeSetImpl::getComparator();
  }
  const AbstractComparator *getComparator()              const          {
    return TreeSetImpl::getComparator();
  }
  AbstractCollection *clone(bool cloneData)              const override {
    throwUnsupportedOperationException(__TFUNCTION__);
    return NULL;
  }
  AbstractMap *cloneMap(bool cloneData)                  const override;
  AbstractIterator *getIterator()                              override;
  AbstractIterator *getKeyIterator()                           override {
    return TreeSetImpl::getIterator();
  }
};

template <typename K, typename V> class TreeMap : public Map<K, V> {
public:
  TreeMap(int (*comparator)(const K &key1, const K &key2))
    : Map<K, V>(new TreeMapImpl(ObjectManager<K>(), ObjectManager<V>(), FunctionComparator<K>(comparator)))
  {
  }
  TreeMap(int (*comparator)(const K *key1, const K *key2))
    : Map<K, V>(new TreeMapImpl(ObjectManager<K>(), ObjectManager<V>(), FunctionComparator<K>(comparator)))
  {
  }
  TreeMap(Comparator<K> &comparator)
    : Map<K, V>(new TreeMapImpl(ObjectManager<K>(), ObjectManager<V>(), comparator))
  {
  }
};

template <typename T> class ShortTreeMap : public TreeMap<short, T>  {
public:
  ShortTreeMap() : TreeMap<short, T>(shortHashCmp) {
  }
};

template <typename T> class UShortTreeMap : public TreeMap<USHORT, T>  {
public:
  UShortTreeMap() : TreeMap<USHORT, T>(ushortHashCmp) {
  }
};

template <typename T> class IntTreeMap : public TreeMap<int, T>    {
public:
  IntTreeMap() : TreeMap<int, T>(intHashCmp) {
  }
};

template <typename T> class UIntTreeMap : public TreeMap<UINT, T>    {
public:
  UIntTreeMap() : TreeMap<UINT, T>(uintHashCmp) {
  }
};

template <typename T> class LongTreeMap : public TreeMap<long, T> {
public:
  LongTreeMap() : TreeMap<long, T>(longHashCmp) {
  }
};

template <typename T> class ULongTreeMap : public TreeMap<ULONG, T> {
public:
  ULongTreeMap() : TreeMap<ULONG, T>(ulongHashCmp) {
  }
};

template <typename T> class Int64TreeMap       : public TreeMap<INT64, T> {
public:
  Int64TreeMap()   : TreeMap<INT64, T>(int64HashCmp) {
  }
};

template <typename T> class UInt64TreeMap      : public TreeMap<UINT64, T> {
public:
  UInt64TreeMap()   : TreeMap<UINT64, T>(uint64HashCmp) {
  }
};

template <typename T> class FloatTreeMap      : public TreeMap<float, T> {
public:
  FloatTreeMap()  : TreeMap<float, T>(floatHashCmp) {
  }
};

template <typename T> class DoubleTreeMap      : public TreeMap<double, T> {
public:
  DoubleTreeMap()  : TreeMap<double, T>(doubleHashCmp) {
  }
};

template <typename T> class StrTreeMap : public TreeMap<const TCHAR*, T> {
public:
  StrTreeMap() : TreeMap<const TCHAR*, T>(strHashCmp) {
  }
};

template <typename T> class StrITreeMap : public TreeMap<const TCHAR*, T> {
public:
  StrITreeMap() : TreeMap<const TCHAR*, T>(striHashCmp) {
  }
};

template <typename T> class StringTreeMap : public TreeMap<String, T> {
public:
  StringTreeMap() : TreeMap<String, T>(stringHashCmp) {
  }
};

template <typename T> class StringITreeMap : public TreeMap<String, T> {
public:
  StringITreeMap() : TreeMap<String, T>(stringiHashCmp) {
  }
};
