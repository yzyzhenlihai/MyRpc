// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace contacts {
PROTOBUF_CONSTEXPR Address::Address(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.addr_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.num_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AddressDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AddressDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~AddressDefaultTypeInternal() {}
  union {
    Address _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AddressDefaultTypeInternal _Address_default_instance_;
PROTOBUF_CONSTEXPR Person::Person(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{}
  , /*decltype(_impl_.addr_)*/nullptr
  , /*decltype(_impl_.age_)*/0
  , /*decltype(_impl_.sex_)*/0
  , /*decltype(_impl_.color_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace contacts
static ::_pb::Metadata file_level_metadata_test_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_test_2eproto[1];
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_test_2eproto[1];

const uint32_t TableStruct_test_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::contacts::Address, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::contacts::Address, _impl_.num_),
  PROTOBUF_FIELD_OFFSET(::contacts::Address, _impl_.addr_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _impl_.age_),
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _impl_.sex_),
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _impl_.addr_),
  PROTOBUF_FIELD_OFFSET(::contacts::Person, _impl_.color_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::contacts::Address)},
  { 8, -1, -1, sizeof(::contacts::Person)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::contacts::_Address_default_instance_._instance,
  &::contacts::_Person_default_instance_._instance,
};

const char descriptor_table_protodef_test_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ntest.proto\022\010contacts\"$\n\007Address\022\013\n\003num"
  "\030\001 \001(\005\022\014\n\004addr\030\002 \001(\014\"q\n\006Person\022\014\n\004name\030\001"
  " \003(\014\022\013\n\003age\030\002 \001(\005\022\013\n\003sex\030\003 \001(\005\022\037\n\004addr\030\004"
  " \001(\0132\021.contacts.Address\022\036\n\005color\030\005 \001(\0162\017"
  ".contacts.Color*\032\n\005Color\022\007\n\003Red\020\000\022\010\n\004Blu"
  "e\020\00627\n\007RpcFunc\022,\n\005Login\022\021.contacts.Addre"
  "ss\032\020.contacts.PersonB\003\200\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_test_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_test_2eproto = {
    false, false, 273, descriptor_table_protodef_test_2eproto,
    "test.proto",
    &descriptor_table_test_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_test_2eproto::offsets,
    file_level_metadata_test_2eproto, file_level_enum_descriptors_test_2eproto,
    file_level_service_descriptors_test_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_test_2eproto_getter() {
  return &descriptor_table_test_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_test_2eproto(&descriptor_table_test_2eproto);
namespace contacts {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Color_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_test_2eproto);
  return file_level_enum_descriptors_test_2eproto[0];
}
bool Color_IsValid(int value) {
  switch (value) {
    case 0:
    case 6:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class Address::_Internal {
 public:
};

Address::Address(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:contacts.Address)
}
Address::Address(const Address& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Address* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.addr_){}
    , decltype(_impl_.num_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.addr_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.addr_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_addr().empty()) {
    _this->_impl_.addr_.Set(from._internal_addr(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.num_ = from._impl_.num_;
  // @@protoc_insertion_point(copy_constructor:contacts.Address)
}

inline void Address::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.addr_){}
    , decltype(_impl_.num_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.addr_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.addr_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Address::~Address() {
  // @@protoc_insertion_point(destructor:contacts.Address)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Address::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.addr_.Destroy();
}

void Address::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Address::Clear() {
// @@protoc_insertion_point(message_clear_start:contacts.Address)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.addr_.ClearToEmpty();
  _impl_.num_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Address::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 num = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.num_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes addr = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_addr();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Address::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:contacts.Address)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 num = 1;
  if (this->_internal_num() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_num(), target);
  }

  // bytes addr = 2;
  if (!this->_internal_addr().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_addr(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:contacts.Address)
  return target;
}

size_t Address::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:contacts.Address)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes addr = 2;
  if (!this->_internal_addr().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_addr());
  }

  // int32 num = 1;
  if (this->_internal_num() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_num());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Address::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Address::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Address::GetClassData() const { return &_class_data_; }


void Address::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Address*>(&to_msg);
  auto& from = static_cast<const Address&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:contacts.Address)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_addr().empty()) {
    _this->_internal_set_addr(from._internal_addr());
  }
  if (from._internal_num() != 0) {
    _this->_internal_set_num(from._internal_num());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Address::CopyFrom(const Address& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:contacts.Address)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Address::IsInitialized() const {
  return true;
}

void Address::InternalSwap(Address* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.addr_, lhs_arena,
      &other->_impl_.addr_, rhs_arena
  );
  swap(_impl_.num_, other->_impl_.num_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Address::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_2eproto_getter, &descriptor_table_test_2eproto_once,
      file_level_metadata_test_2eproto[0]);
}

// ===================================================================

class Person::_Internal {
 public:
  static const ::contacts::Address& addr(const Person* msg);
};

const ::contacts::Address&
Person::_Internal::addr(const Person* msg) {
  return *msg->_impl_.addr_;
}
Person::Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:contacts.Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){from._impl_.name_}
    , decltype(_impl_.addr_){nullptr}
    , decltype(_impl_.age_){}
    , decltype(_impl_.sex_){}
    , decltype(_impl_.color_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_addr()) {
    _this->_impl_.addr_ = new ::contacts::Address(*from._impl_.addr_);
  }
  ::memcpy(&_impl_.age_, &from._impl_.age_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.color_) -
    reinterpret_cast<char*>(&_impl_.age_)) + sizeof(_impl_.color_));
  // @@protoc_insertion_point(copy_constructor:contacts.Person)
}

inline void Person::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){arena}
    , decltype(_impl_.addr_){nullptr}
    , decltype(_impl_.age_){0}
    , decltype(_impl_.sex_){0}
    , decltype(_impl_.color_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:contacts.Person)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Person::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.~RepeatedPtrField();
  if (this != internal_default_instance()) delete _impl_.addr_;
}

void Person::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:contacts.Person)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.Clear();
  if (GetArenaForAllocation() == nullptr && _impl_.addr_ != nullptr) {
    delete _impl_.addr_;
  }
  _impl_.addr_ = nullptr;
  ::memset(&_impl_.age_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.color_) -
      reinterpret_cast<char*>(&_impl_.age_)) + sizeof(_impl_.color_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated bytes name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_name();
            ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else
          goto handle_unusual;
        continue;
      // int32 age = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.age_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 sex = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.sex_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .contacts.Address addr = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr = ctx->ParseMessage(_internal_mutable_addr(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .contacts.Color color = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_color(static_cast<::contacts::Color>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:contacts.Person)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated bytes name = 1;
  for (int i = 0, n = this->_internal_name_size(); i < n; i++) {
    const auto& s = this->_internal_name(i);
    target = stream->WriteBytes(1, s, target);
  }

  // int32 age = 2;
  if (this->_internal_age() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_age(), target);
  }

  // int32 sex = 3;
  if (this->_internal_sex() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_sex(), target);
  }

  // .contacts.Address addr = 4;
  if (this->_internal_has_addr()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(4, _Internal::addr(this),
        _Internal::addr(this).GetCachedSize(), target, stream);
  }

  // .contacts.Color color = 5;
  if (this->_internal_color() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      5, this->_internal_color(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:contacts.Person)
  return target;
}

size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:contacts.Person)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated bytes name = 1;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_impl_.name_.size());
  for (int i = 0, n = _impl_.name_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
      _impl_.name_.Get(i));
  }

  // .contacts.Address addr = 4;
  if (this->_internal_has_addr()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.addr_);
  }

  // int32 age = 2;
  if (this->_internal_age() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_age());
  }

  // int32 sex = 3;
  if (this->_internal_sex() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_sex());
  }

  // .contacts.Color color = 5;
  if (this->_internal_color() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_color());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person::GetClassData() const { return &_class_data_; }


void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:contacts.Person)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.name_.MergeFrom(from._impl_.name_);
  if (from._internal_has_addr()) {
    _this->_internal_mutable_addr()->::contacts::Address::MergeFrom(
        from._internal_addr());
  }
  if (from._internal_age() != 0) {
    _this->_internal_set_age(from._internal_age());
  }
  if (from._internal_sex() != 0) {
    _this->_internal_set_sex(from._internal_sex());
  }
  if (from._internal_color() != 0) {
    _this->_internal_set_color(from._internal_color());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:contacts.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.name_.InternalSwap(&other->_impl_.name_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Person, _impl_.color_)
      + sizeof(Person::_impl_.color_)
      - PROTOBUF_FIELD_OFFSET(Person, _impl_.addr_)>(
          reinterpret_cast<char*>(&_impl_.addr_),
          reinterpret_cast<char*>(&other->_impl_.addr_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_2eproto_getter, &descriptor_table_test_2eproto_once,
      file_level_metadata_test_2eproto[1]);
}

// ===================================================================

RpcFunc::~RpcFunc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* RpcFunc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_test_2eproto);
  return file_level_service_descriptors_test_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* RpcFunc::GetDescriptor() {
  return descriptor();
}

void RpcFunc::Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::contacts::Address*,
                         ::contacts::Person*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Login() not implemented.");
  done->Run();
}

void RpcFunc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_test_2eproto[0]);
  switch(method->index()) {
    case 0:
      Login(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::contacts::Address*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::contacts::Person*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& RpcFunc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::contacts::Address::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& RpcFunc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::contacts::Person::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

RpcFunc_Stub::RpcFunc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
RpcFunc_Stub::RpcFunc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
RpcFunc_Stub::~RpcFunc_Stub() {
  if (owns_channel_) delete channel_;
}

void RpcFunc_Stub::Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::contacts::Address* request,
                              ::contacts::Person* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace contacts
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::contacts::Address*
Arena::CreateMaybeMessage< ::contacts::Address >(Arena* arena) {
  return Arena::CreateMessageInternal< ::contacts::Address >(arena);
}
template<> PROTOBUF_NOINLINE ::contacts::Person*
Arena::CreateMaybeMessage< ::contacts::Person >(Arena* arena) {
  return Arena::CreateMessageInternal< ::contacts::Person >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
