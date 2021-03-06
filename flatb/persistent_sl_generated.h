// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_PERSISTENTSL_NVRDB_H_
#define FLATBUFFERS_GENERATED_PERSISTENTSL_NVRDB_H_

#include "flatbuffers/flatbuffers.h"

namespace nvrdb {

struct Header;

struct IndexNode;

struct StringKey;

struct IntKey;

enum Key {
  Key_NONE = 0,
  Key_StringKey = 1,
  Key_IntKey = 2,
  Key_MIN = Key_NONE,
  Key_MAX = Key_IntKey
};

inline const Key (&EnumValuesKey())[3] {
  static const Key values[] = {
    Key_NONE,
    Key_StringKey,
    Key_IntKey
  };
  return values;
}

inline const char * const *EnumNamesKey() {
  static const char * const names[] = {
    "NONE",
    "StringKey",
    "IntKey",
    nullptr
  };
  return names;
}

inline const char *EnumNameKey(Key e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesKey()[index];
}

template<typename T> struct KeyTraits {
  static const Key enum_value = Key_NONE;
};

template<> struct KeyTraits<StringKey> {
  static const Key enum_value = Key_StringKey;
};

template<> struct KeyTraits<IntKey> {
  static const Key enum_value = Key_IntKey;
};

bool VerifyKey(flatbuffers::Verifier &verifier, const void *obj, Key type);
bool VerifyKeyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Header FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_VERSION = 6,
    VT_COUNT = 8,
    VT_BUFFERED_COUNT = 10,
    VT_LIST_START = 12,
    VT_LIST_END = 14,
    VT_BUFFER_START = 16,
    VT_BUFFER_END = 18
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  flatbuffers::String *mutable_name() {
    return GetPointer<flatbuffers::String *>(VT_NAME);
  }
  int32_t version() const {
    return GetField<int32_t>(VT_VERSION, 0);
  }
  bool mutate_version(int32_t _version) {
    return SetField<int32_t>(VT_VERSION, _version, 0);
  }
  int64_t count() const {
    return GetField<int64_t>(VT_COUNT, 0);
  }
  bool mutate_count(int64_t _count) {
    return SetField<int64_t>(VT_COUNT, _count, 0);
  }
  int64_t buffered_count() const {
    return GetField<int64_t>(VT_BUFFERED_COUNT, 0);
  }
  bool mutate_buffered_count(int64_t _buffered_count) {
    return SetField<int64_t>(VT_BUFFERED_COUNT, _buffered_count, 0);
  }
  int64_t list_start() const {
    return GetField<int64_t>(VT_LIST_START, 0);
  }
  bool mutate_list_start(int64_t _list_start) {
    return SetField<int64_t>(VT_LIST_START, _list_start, 0);
  }
  int64_t list_end() const {
    return GetField<int64_t>(VT_LIST_END, 0);
  }
  bool mutate_list_end(int64_t _list_end) {
    return SetField<int64_t>(VT_LIST_END, _list_end, 0);
  }
  int64_t buffer_start() const {
    return GetField<int64_t>(VT_BUFFER_START, 0);
  }
  bool mutate_buffer_start(int64_t _buffer_start) {
    return SetField<int64_t>(VT_BUFFER_START, _buffer_start, 0);
  }
  int64_t buffer_end() const {
    return GetField<int64_t>(VT_BUFFER_END, 0);
  }
  bool mutate_buffer_end(int64_t _buffer_end) {
    return SetField<int64_t>(VT_BUFFER_END, _buffer_end, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_VERSION) &&
           VerifyField<int64_t>(verifier, VT_COUNT) &&
           VerifyField<int64_t>(verifier, VT_BUFFERED_COUNT) &&
           VerifyField<int64_t>(verifier, VT_LIST_START) &&
           VerifyField<int64_t>(verifier, VT_LIST_END) &&
           VerifyField<int64_t>(verifier, VT_BUFFER_START) &&
           VerifyField<int64_t>(verifier, VT_BUFFER_END) &&
           verifier.EndTable();
  }
};

struct HeaderBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Header::VT_NAME, name);
  }
  void add_version(int32_t version) {
    fbb_.AddElement<int32_t>(Header::VT_VERSION, version, 0);
  }
  void add_count(int64_t count) {
    fbb_.AddElement<int64_t>(Header::VT_COUNT, count, 0);
  }
  void add_buffered_count(int64_t buffered_count) {
    fbb_.AddElement<int64_t>(Header::VT_BUFFERED_COUNT, buffered_count, 0);
  }
  void add_list_start(int64_t list_start) {
    fbb_.AddElement<int64_t>(Header::VT_LIST_START, list_start, 0);
  }
  void add_list_end(int64_t list_end) {
    fbb_.AddElement<int64_t>(Header::VT_LIST_END, list_end, 0);
  }
  void add_buffer_start(int64_t buffer_start) {
    fbb_.AddElement<int64_t>(Header::VT_BUFFER_START, buffer_start, 0);
  }
  void add_buffer_end(int64_t buffer_end) {
    fbb_.AddElement<int64_t>(Header::VT_BUFFER_END, buffer_end, 0);
  }
  explicit HeaderBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  HeaderBuilder &operator=(const HeaderBuilder &);
  flatbuffers::Offset<Header> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Header>(end);
    return o;
  }
};

inline flatbuffers::Offset<Header> CreateHeader(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t version = 0,
    int64_t count = 0,
    int64_t buffered_count = 0,
    int64_t list_start = 0,
    int64_t list_end = 0,
    int64_t buffer_start = 0,
    int64_t buffer_end = 0) {
  HeaderBuilder builder_(_fbb);
  builder_.add_buffer_end(buffer_end);
  builder_.add_buffer_start(buffer_start);
  builder_.add_list_end(list_end);
  builder_.add_list_start(list_start);
  builder_.add_buffered_count(buffered_count);
  builder_.add_count(count);
  builder_.add_version(version);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Header> CreateHeaderDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t version = 0,
    int64_t count = 0,
    int64_t buffered_count = 0,
    int64_t list_start = 0,
    int64_t list_end = 0,
    int64_t buffer_start = 0,
    int64_t buffer_end = 0) {
  return nvrdb::CreateHeader(
      _fbb,
      name ? _fbb.CreateString(name) : 0,
      version,
      count,
      buffered_count,
      list_start,
      list_end,
      buffer_start,
      buffer_end);
}

struct IndexNode FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_KEY_TYPE = 4,
    VT_KEY = 6,
    VT_DOCS = 8
  };
  Key key_type() const {
    return static_cast<Key>(GetField<uint8_t>(VT_KEY_TYPE, 0));
  }
  bool mutate_key_type(Key _key_type) {
    return SetField<uint8_t>(VT_KEY_TYPE, static_cast<uint8_t>(_key_type), 0);
  }
  const void *key() const {
    return GetPointer<const void *>(VT_KEY);
  }
  template<typename T> const T *key_as() const;
  const StringKey *key_as_StringKey() const {
    return key_type() == Key_StringKey ? static_cast<const StringKey *>(key()) : nullptr;
  }
  const IntKey *key_as_IntKey() const {
    return key_type() == Key_IntKey ? static_cast<const IntKey *>(key()) : nullptr;
  }
  void *mutable_key() {
    return GetPointer<void *>(VT_KEY);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *docs() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_DOCS);
  }
  flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *mutable_docs() {
    return GetPointer<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_DOCS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_KEY_TYPE) &&
           VerifyOffset(verifier, VT_KEY) &&
           VerifyKey(verifier, key(), key_type()) &&
           VerifyOffset(verifier, VT_DOCS) &&
           verifier.VerifyVector(docs()) &&
           verifier.VerifyVectorOfStrings(docs()) &&
           verifier.EndTable();
  }
};

template<> inline const StringKey *IndexNode::key_as<StringKey>() const {
  return key_as_StringKey();
}

template<> inline const IntKey *IndexNode::key_as<IntKey>() const {
  return key_as_IntKey();
}

struct IndexNodeBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key_type(Key key_type) {
    fbb_.AddElement<uint8_t>(IndexNode::VT_KEY_TYPE, static_cast<uint8_t>(key_type), 0);
  }
  void add_key(flatbuffers::Offset<void> key) {
    fbb_.AddOffset(IndexNode::VT_KEY, key);
  }
  void add_docs(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> docs) {
    fbb_.AddOffset(IndexNode::VT_DOCS, docs);
  }
  explicit IndexNodeBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  IndexNodeBuilder &operator=(const IndexNodeBuilder &);
  flatbuffers::Offset<IndexNode> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<IndexNode>(end);
    return o;
  }
};

inline flatbuffers::Offset<IndexNode> CreateIndexNode(
    flatbuffers::FlatBufferBuilder &_fbb,
    Key key_type = Key_NONE,
    flatbuffers::Offset<void> key = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> docs = 0) {
  IndexNodeBuilder builder_(_fbb);
  builder_.add_docs(docs);
  builder_.add_key(key);
  builder_.add_key_type(key_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<IndexNode> CreateIndexNodeDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    Key key_type = Key_NONE,
    flatbuffers::Offset<void> key = 0,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *docs = nullptr) {
  return nvrdb::CreateIndexNode(
      _fbb,
      key_type,
      key,
      docs ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*docs) : 0);
}

struct StringKey FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TOKEN = 4
  };
  const flatbuffers::String *token() const {
    return GetPointer<const flatbuffers::String *>(VT_TOKEN);
  }
  flatbuffers::String *mutable_token() {
    return GetPointer<flatbuffers::String *>(VT_TOKEN);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TOKEN) &&
           verifier.VerifyString(token()) &&
           verifier.EndTable();
  }
};

struct StringKeyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_token(flatbuffers::Offset<flatbuffers::String> token) {
    fbb_.AddOffset(StringKey::VT_TOKEN, token);
  }
  explicit StringKeyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  StringKeyBuilder &operator=(const StringKeyBuilder &);
  flatbuffers::Offset<StringKey> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<StringKey>(end);
    return o;
  }
};

inline flatbuffers::Offset<StringKey> CreateStringKey(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> token = 0) {
  StringKeyBuilder builder_(_fbb);
  builder_.add_token(token);
  return builder_.Finish();
}

inline flatbuffers::Offset<StringKey> CreateStringKeyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *token = nullptr) {
  return nvrdb::CreateStringKey(
      _fbb,
      token ? _fbb.CreateString(token) : 0);
}

struct IntKey FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TOKEN = 4
  };
  int32_t token() const {
    return GetField<int32_t>(VT_TOKEN, 0);
  }
  bool mutate_token(int32_t _token) {
    return SetField<int32_t>(VT_TOKEN, _token, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_TOKEN) &&
           verifier.EndTable();
  }
};

struct IntKeyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_token(int32_t token) {
    fbb_.AddElement<int32_t>(IntKey::VT_TOKEN, token, 0);
  }
  explicit IntKeyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  IntKeyBuilder &operator=(const IntKeyBuilder &);
  flatbuffers::Offset<IntKey> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<IntKey>(end);
    return o;
  }
};

inline flatbuffers::Offset<IntKey> CreateIntKey(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t token = 0) {
  IntKeyBuilder builder_(_fbb);
  builder_.add_token(token);
  return builder_.Finish();
}

inline bool VerifyKey(flatbuffers::Verifier &verifier, const void *obj, Key type) {
  switch (type) {
    case Key_NONE: {
      return true;
    }
    case Key_StringKey: {
      auto ptr = reinterpret_cast<const StringKey *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Key_IntKey: {
      auto ptr = reinterpret_cast<const IntKey *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyKeyVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyKey(
        verifier,  values->Get(i), types->GetEnum<Key>(i))) {
      return false;
    }
  }
  return true;
}

}  // namespace nvrdb

#endif  // FLATBUFFERS_GENERATED_PERSISTENTSL_NVRDB_H_
