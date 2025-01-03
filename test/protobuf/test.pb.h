// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto;
namespace contacts {
class Address;
struct AddressDefaultTypeInternal;
extern AddressDefaultTypeInternal _Address_default_instance_;
class Person;
struct PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace contacts
PROTOBUF_NAMESPACE_OPEN
template<> ::contacts::Address* Arena::CreateMaybeMessage<::contacts::Address>(Arena*);
template<> ::contacts::Person* Arena::CreateMaybeMessage<::contacts::Person>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace contacts {

enum Color : int {
  Red = 0,
  Blue = 6,
  Color_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  Color_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool Color_IsValid(int value);
constexpr Color Color_MIN = Red;
constexpr Color Color_MAX = Blue;
constexpr int Color_ARRAYSIZE = Color_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Color_descriptor();
template<typename T>
inline const std::string& Color_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Color>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Color_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Color_descriptor(), enum_t_value);
}
inline bool Color_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Color* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Color>(
    Color_descriptor(), name, value);
}
// ===================================================================

class Address final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:contacts.Address) */ {
 public:
  inline Address() : Address(nullptr) {}
  ~Address() override;
  explicit PROTOBUF_CONSTEXPR Address(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Address(const Address& from);
  Address(Address&& from) noexcept
    : Address() {
    *this = ::std::move(from);
  }

  inline Address& operator=(const Address& from) {
    CopyFrom(from);
    return *this;
  }
  inline Address& operator=(Address&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Address& default_instance() {
    return *internal_default_instance();
  }
  static inline const Address* internal_default_instance() {
    return reinterpret_cast<const Address*>(
               &_Address_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Address& a, Address& b) {
    a.Swap(&b);
  }
  inline void Swap(Address* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Address* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Address* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Address>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Address& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Address& from) {
    Address::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Address* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "contacts.Address";
  }
  protected:
  explicit Address(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAddrFieldNumber = 2,
    kNumFieldNumber = 1,
  };
  // bytes addr = 2;
  void clear_addr();
  const std::string& addr() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_addr(ArgT0&& arg0, ArgT... args);
  std::string* mutable_addr();
  PROTOBUF_NODISCARD std::string* release_addr();
  void set_allocated_addr(std::string* addr);
  private:
  const std::string& _internal_addr() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_addr(const std::string& value);
  std::string* _internal_mutable_addr();
  public:

  // int32 num = 1;
  void clear_num();
  int32_t num() const;
  void set_num(int32_t value);
  private:
  int32_t _internal_num() const;
  void _internal_set_num(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:contacts.Address)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr addr_;
    int32_t num_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_test_2eproto;
};
// -------------------------------------------------------------------

class Person final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:contacts.Person) */ {
 public:
  inline Person() : Person(nullptr) {}
  ~Person() override;
  explicit PROTOBUF_CONSTEXPR Person(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Person(const Person& from);
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person& operator=(Person&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }
  inline void Swap(Person* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Person& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Person& from) {
    Person::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "contacts.Person";
  }
  protected:
  explicit Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kAddrFieldNumber = 4,
    kAgeFieldNumber = 2,
    kSexFieldNumber = 3,
    kColorFieldNumber = 5,
  };
  // repeated bytes name = 1;
  int name_size() const;
  private:
  int _internal_name_size() const;
  public:
  void clear_name();
  const std::string& name(int index) const;
  std::string* mutable_name(int index);
  void set_name(int index, const std::string& value);
  void set_name(int index, std::string&& value);
  void set_name(int index, const char* value);
  void set_name(int index, const void* value, size_t size);
  std::string* add_name();
  void add_name(const std::string& value);
  void add_name(std::string&& value);
  void add_name(const char* value);
  void add_name(const void* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& name() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_name();
  private:
  const std::string& _internal_name(int index) const;
  std::string* _internal_add_name();
  public:

  // .contacts.Address addr = 4;
  bool has_addr() const;
  private:
  bool _internal_has_addr() const;
  public:
  void clear_addr();
  const ::contacts::Address& addr() const;
  PROTOBUF_NODISCARD ::contacts::Address* release_addr();
  ::contacts::Address* mutable_addr();
  void set_allocated_addr(::contacts::Address* addr);
  private:
  const ::contacts::Address& _internal_addr() const;
  ::contacts::Address* _internal_mutable_addr();
  public:
  void unsafe_arena_set_allocated_addr(
      ::contacts::Address* addr);
  ::contacts::Address* unsafe_arena_release_addr();

  // int32 age = 2;
  void clear_age();
  int32_t age() const;
  void set_age(int32_t value);
  private:
  int32_t _internal_age() const;
  void _internal_set_age(int32_t value);
  public:

  // int32 sex = 3;
  void clear_sex();
  int32_t sex() const;
  void set_sex(int32_t value);
  private:
  int32_t _internal_sex() const;
  void _internal_set_sex(int32_t value);
  public:

  // .contacts.Color color = 5;
  void clear_color();
  ::contacts::Color color() const;
  void set_color(::contacts::Color value);
  private:
  ::contacts::Color _internal_color() const;
  void _internal_set_color(::contacts::Color value);
  public:

  // @@protoc_insertion_point(class_scope:contacts.Person)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> name_;
    ::contacts::Address* addr_;
    int32_t age_;
    int32_t sex_;
    int color_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_test_2eproto;
};
// ===================================================================

class RpcFunc_Stub;

class RpcFunc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline RpcFunc() {};
 public:
  virtual ~RpcFunc();

  typedef RpcFunc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::contacts::Address* request,
                       ::contacts::Person* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RpcFunc);
};

class RpcFunc_Stub : public RpcFunc {
 public:
  RpcFunc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  RpcFunc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~RpcFunc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements RpcFunc ------------------------------------------

  void Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::contacts::Address* request,
                       ::contacts::Person* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(RpcFunc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Address

// int32 num = 1;
inline void Address::clear_num() {
  _impl_.num_ = 0;
}
inline int32_t Address::_internal_num() const {
  return _impl_.num_;
}
inline int32_t Address::num() const {
  // @@protoc_insertion_point(field_get:contacts.Address.num)
  return _internal_num();
}
inline void Address::_internal_set_num(int32_t value) {
  
  _impl_.num_ = value;
}
inline void Address::set_num(int32_t value) {
  _internal_set_num(value);
  // @@protoc_insertion_point(field_set:contacts.Address.num)
}

// bytes addr = 2;
inline void Address::clear_addr() {
  _impl_.addr_.ClearToEmpty();
}
inline const std::string& Address::addr() const {
  // @@protoc_insertion_point(field_get:contacts.Address.addr)
  return _internal_addr();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Address::set_addr(ArgT0&& arg0, ArgT... args) {
 
 _impl_.addr_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:contacts.Address.addr)
}
inline std::string* Address::mutable_addr() {
  std::string* _s = _internal_mutable_addr();
  // @@protoc_insertion_point(field_mutable:contacts.Address.addr)
  return _s;
}
inline const std::string& Address::_internal_addr() const {
  return _impl_.addr_.Get();
}
inline void Address::_internal_set_addr(const std::string& value) {
  
  _impl_.addr_.Set(value, GetArenaForAllocation());
}
inline std::string* Address::_internal_mutable_addr() {
  
  return _impl_.addr_.Mutable(GetArenaForAllocation());
}
inline std::string* Address::release_addr() {
  // @@protoc_insertion_point(field_release:contacts.Address.addr)
  return _impl_.addr_.Release();
}
inline void Address::set_allocated_addr(std::string* addr) {
  if (addr != nullptr) {
    
  } else {
    
  }
  _impl_.addr_.SetAllocated(addr, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.addr_.IsDefault()) {
    _impl_.addr_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:contacts.Address.addr)
}

// -------------------------------------------------------------------

// Person

// repeated bytes name = 1;
inline int Person::_internal_name_size() const {
  return _impl_.name_.size();
}
inline int Person::name_size() const {
  return _internal_name_size();
}
inline void Person::clear_name() {
  _impl_.name_.Clear();
}
inline std::string* Person::add_name() {
  std::string* _s = _internal_add_name();
  // @@protoc_insertion_point(field_add_mutable:contacts.Person.name)
  return _s;
}
inline const std::string& Person::_internal_name(int index) const {
  return _impl_.name_.Get(index);
}
inline const std::string& Person::name(int index) const {
  // @@protoc_insertion_point(field_get:contacts.Person.name)
  return _internal_name(index);
}
inline std::string* Person::mutable_name(int index) {
  // @@protoc_insertion_point(field_mutable:contacts.Person.name)
  return _impl_.name_.Mutable(index);
}
inline void Person::set_name(int index, const std::string& value) {
  _impl_.name_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:contacts.Person.name)
}
inline void Person::set_name(int index, std::string&& value) {
  _impl_.name_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:contacts.Person.name)
}
inline void Person::set_name(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.name_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:contacts.Person.name)
}
inline void Person::set_name(int index, const void* value, size_t size) {
  _impl_.name_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:contacts.Person.name)
}
inline std::string* Person::_internal_add_name() {
  return _impl_.name_.Add();
}
inline void Person::add_name(const std::string& value) {
  _impl_.name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:contacts.Person.name)
}
inline void Person::add_name(std::string&& value) {
  _impl_.name_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:contacts.Person.name)
}
inline void Person::add_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:contacts.Person.name)
}
inline void Person::add_name(const void* value, size_t size) {
  _impl_.name_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:contacts.Person.name)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Person::name() const {
  // @@protoc_insertion_point(field_list:contacts.Person.name)
  return _impl_.name_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Person::mutable_name() {
  // @@protoc_insertion_point(field_mutable_list:contacts.Person.name)
  return &_impl_.name_;
}

// int32 age = 2;
inline void Person::clear_age() {
  _impl_.age_ = 0;
}
inline int32_t Person::_internal_age() const {
  return _impl_.age_;
}
inline int32_t Person::age() const {
  // @@protoc_insertion_point(field_get:contacts.Person.age)
  return _internal_age();
}
inline void Person::_internal_set_age(int32_t value) {
  
  _impl_.age_ = value;
}
inline void Person::set_age(int32_t value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:contacts.Person.age)
}

// int32 sex = 3;
inline void Person::clear_sex() {
  _impl_.sex_ = 0;
}
inline int32_t Person::_internal_sex() const {
  return _impl_.sex_;
}
inline int32_t Person::sex() const {
  // @@protoc_insertion_point(field_get:contacts.Person.sex)
  return _internal_sex();
}
inline void Person::_internal_set_sex(int32_t value) {
  
  _impl_.sex_ = value;
}
inline void Person::set_sex(int32_t value) {
  _internal_set_sex(value);
  // @@protoc_insertion_point(field_set:contacts.Person.sex)
}

// .contacts.Address addr = 4;
inline bool Person::_internal_has_addr() const {
  return this != internal_default_instance() && _impl_.addr_ != nullptr;
}
inline bool Person::has_addr() const {
  return _internal_has_addr();
}
inline void Person::clear_addr() {
  if (GetArenaForAllocation() == nullptr && _impl_.addr_ != nullptr) {
    delete _impl_.addr_;
  }
  _impl_.addr_ = nullptr;
}
inline const ::contacts::Address& Person::_internal_addr() const {
  const ::contacts::Address* p = _impl_.addr_;
  return p != nullptr ? *p : reinterpret_cast<const ::contacts::Address&>(
      ::contacts::_Address_default_instance_);
}
inline const ::contacts::Address& Person::addr() const {
  // @@protoc_insertion_point(field_get:contacts.Person.addr)
  return _internal_addr();
}
inline void Person::unsafe_arena_set_allocated_addr(
    ::contacts::Address* addr) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.addr_);
  }
  _impl_.addr_ = addr;
  if (addr) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:contacts.Person.addr)
}
inline ::contacts::Address* Person::release_addr() {
  
  ::contacts::Address* temp = _impl_.addr_;
  _impl_.addr_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::contacts::Address* Person::unsafe_arena_release_addr() {
  // @@protoc_insertion_point(field_release:contacts.Person.addr)
  
  ::contacts::Address* temp = _impl_.addr_;
  _impl_.addr_ = nullptr;
  return temp;
}
inline ::contacts::Address* Person::_internal_mutable_addr() {
  
  if (_impl_.addr_ == nullptr) {
    auto* p = CreateMaybeMessage<::contacts::Address>(GetArenaForAllocation());
    _impl_.addr_ = p;
  }
  return _impl_.addr_;
}
inline ::contacts::Address* Person::mutable_addr() {
  ::contacts::Address* _msg = _internal_mutable_addr();
  // @@protoc_insertion_point(field_mutable:contacts.Person.addr)
  return _msg;
}
inline void Person::set_allocated_addr(::contacts::Address* addr) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.addr_;
  }
  if (addr) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(addr);
    if (message_arena != submessage_arena) {
      addr = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, addr, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.addr_ = addr;
  // @@protoc_insertion_point(field_set_allocated:contacts.Person.addr)
}

// .contacts.Color color = 5;
inline void Person::clear_color() {
  _impl_.color_ = 0;
}
inline ::contacts::Color Person::_internal_color() const {
  return static_cast< ::contacts::Color >(_impl_.color_);
}
inline ::contacts::Color Person::color() const {
  // @@protoc_insertion_point(field_get:contacts.Person.color)
  return _internal_color();
}
inline void Person::_internal_set_color(::contacts::Color value) {
  
  _impl_.color_ = value;
}
inline void Person::set_color(::contacts::Color value) {
  _internal_set_color(value);
  // @@protoc_insertion_point(field_set:contacts.Person.color)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace contacts

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::contacts::Color> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::contacts::Color>() {
  return ::contacts::Color_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_2eproto
