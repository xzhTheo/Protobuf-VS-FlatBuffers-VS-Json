// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_lite_imports_nonlite.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include <google/protobuf/unittest_lite_imports_nonlite.pb.h>

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
// @@protoc_insertion_point(includes)

namespace protobuf_unittest {
class TestLiteImportsNonliteDefaultTypeInternal {
public:
 ::google::protobuf::internal::ExplicitlyConstructed<TestLiteImportsNonlite>
     _instance;
} _TestLiteImportsNonlite_default_instance_;

namespace protobuf_google_2fprotobuf_2funittest_5flite_5fimports_5fnonlite_2eproto {

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] GOOGLE_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { NULL, NULL, 0, -1, -1, -1, -1, NULL, false },
};

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  ::protobuf_unittest::protobuf_google_2fprotobuf_2funittest_2eproto::InitDefaults();
  _TestLiteImportsNonlite_default_instance_._instance.DefaultConstruct();
  ::google::protobuf::internal::OnShutdownDestroyMessage(
      &_TestLiteImportsNonlite_default_instance_);_TestLiteImportsNonlite_default_instance_._instance.get_mutable()->message_ = const_cast< ::protobuf_unittest::TestAllTypes*>(
      ::protobuf_unittest::TestAllTypes::internal_default_instance());
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
namespace {
void AddDescriptorsImpl() {
  InitDefaults();
  ::protobuf_unittest::protobuf_google_2fprotobuf_2funittest_2eproto::AddDescriptors();
}
} // anonymous namespace

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}

}  // namespace protobuf_google_2fprotobuf_2funittest_5flite_5fimports_5fnonlite_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TestLiteImportsNonlite::kMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TestLiteImportsNonlite::TestLiteImportsNonlite()
  : ::google::protobuf::MessageLite(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_google_2fprotobuf_2funittest_5flite_5fimports_5fnonlite_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:protobuf_unittest.TestLiteImportsNonlite)
}
TestLiteImportsNonlite::TestLiteImportsNonlite(const TestLiteImportsNonlite& from)
  : ::google::protobuf::MessageLite(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_message()) {
    message_ = new ::protobuf_unittest::TestAllTypes(*from.message_);
  } else {
    message_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:protobuf_unittest.TestLiteImportsNonlite)
}

void TestLiteImportsNonlite::SharedCtor() {
  _cached_size_ = 0;
  message_ = NULL;
}

TestLiteImportsNonlite::~TestLiteImportsNonlite() {
  // @@protoc_insertion_point(destructor:protobuf_unittest.TestLiteImportsNonlite)
  SharedDtor();
}

void TestLiteImportsNonlite::SharedDtor() {
  if (this != internal_default_instance()) delete message_;
}

void TestLiteImportsNonlite::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const TestLiteImportsNonlite& TestLiteImportsNonlite::default_instance() {
  protobuf_google_2fprotobuf_2funittest_5flite_5fimports_5fnonlite_2eproto::InitDefaults();
  return *internal_default_instance();
}

TestLiteImportsNonlite* TestLiteImportsNonlite::New(::google::protobuf::Arena* arena) const {
  TestLiteImportsNonlite* n = new TestLiteImportsNonlite;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void TestLiteImportsNonlite::Clear() {
// @@protoc_insertion_point(message_clear_start:protobuf_unittest.TestLiteImportsNonlite)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (has_message()) {
    GOOGLE_DCHECK(message_ != NULL);
    message_->::protobuf_unittest::TestAllTypes::Clear();
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool TestLiteImportsNonlite::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  ::google::protobuf::io::LazyStringOutputStream unknown_fields_string(
      ::google::protobuf::NewPermanentCallback(&_internal_metadata_,
          &::google::protobuf::internal::InternalMetadataWithArenaLite::
              mutable_unknown_fields));
  ::google::protobuf::io::CodedOutputStream unknown_fields_stream(
      &unknown_fields_string, false);
  // @@protoc_insertion_point(parse_start:protobuf_unittest.TestLiteImportsNonlite)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protobuf_unittest.TestAllTypes message = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_message()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(
            input, tag, &unknown_fields_stream));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protobuf_unittest.TestLiteImportsNonlite)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protobuf_unittest.TestLiteImportsNonlite)
  return false;
#undef DO_
}

void TestLiteImportsNonlite::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protobuf_unittest.TestLiteImportsNonlite)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .protobuf_unittest.TestAllTypes message = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->message_, output);
  }

  output->WriteRaw(_internal_metadata_.unknown_fields().data(),
                   static_cast<int>(_internal_metadata_.unknown_fields().size()));
  // @@protoc_insertion_point(serialize_end:protobuf_unittest.TestLiteImportsNonlite)
}

size_t TestLiteImportsNonlite::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:protobuf_unittest.TestLiteImportsNonlite)
  size_t total_size = 0;

  total_size += _internal_metadata_.unknown_fields().size();

  // optional .protobuf_unittest.TestAllTypes message = 1;
  if (has_message()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->message_);
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void TestLiteImportsNonlite::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const TestLiteImportsNonlite*>(&from));
}

void TestLiteImportsNonlite::MergeFrom(const TestLiteImportsNonlite& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:protobuf_unittest.TestLiteImportsNonlite)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_message()) {
    mutable_message()->::protobuf_unittest::TestAllTypes::MergeFrom(from.message());
  }
}

void TestLiteImportsNonlite::CopyFrom(const TestLiteImportsNonlite& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:protobuf_unittest.TestLiteImportsNonlite)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TestLiteImportsNonlite::IsInitialized() const {
  return true;
}

void TestLiteImportsNonlite::Swap(TestLiteImportsNonlite* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TestLiteImportsNonlite::InternalSwap(TestLiteImportsNonlite* other) {
  using std::swap;
  swap(message_, other->message_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::std::string TestLiteImportsNonlite::GetTypeName() const {
  return "protobuf_unittest.TestLiteImportsNonlite";
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// TestLiteImportsNonlite

// optional .protobuf_unittest.TestAllTypes message = 1;
bool TestLiteImportsNonlite::has_message() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void TestLiteImportsNonlite::set_has_message() {
  _has_bits_[0] |= 0x00000001u;
}
void TestLiteImportsNonlite::clear_has_message() {
  _has_bits_[0] &= ~0x00000001u;
}
void TestLiteImportsNonlite::clear_message() {
  if (message_ != NULL) message_->::protobuf_unittest::TestAllTypes::Clear();
  clear_has_message();
}
const ::protobuf_unittest::TestAllTypes& TestLiteImportsNonlite::message() const {
  const ::protobuf_unittest::TestAllTypes* p = message_;
  // @@protoc_insertion_point(field_get:protobuf_unittest.TestLiteImportsNonlite.message)
  return p != NULL ? *p : *reinterpret_cast<const ::protobuf_unittest::TestAllTypes*>(
      &::protobuf_unittest::_TestAllTypes_default_instance_);
}
::protobuf_unittest::TestAllTypes* TestLiteImportsNonlite::mutable_message() {
  set_has_message();
  if (message_ == NULL) {
    message_ = new ::protobuf_unittest::TestAllTypes;
  }
  // @@protoc_insertion_point(field_mutable:protobuf_unittest.TestLiteImportsNonlite.message)
  return message_;
}
::protobuf_unittest::TestAllTypes* TestLiteImportsNonlite::release_message() {
  // @@protoc_insertion_point(field_release:protobuf_unittest.TestLiteImportsNonlite.message)
  clear_has_message();
  ::protobuf_unittest::TestAllTypes* temp = message_;
  message_ = NULL;
  return temp;
}
void TestLiteImportsNonlite::set_allocated_message(::protobuf_unittest::TestAllTypes* message) {
  delete message_;
  if (message != NULL && message->GetArena() != NULL) {
    ::protobuf_unittest::TestAllTypes* new_message = new ::protobuf_unittest::TestAllTypes;
    new_message->CopyFrom(*message);
    message = new_message;
  }
  message_ = message;
  if (message) {
    set_has_message();
  } else {
    clear_has_message();
  }
  // @@protoc_insertion_point(field_set_allocated:protobuf_unittest.TestLiteImportsNonlite.message)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf_unittest

// @@protoc_insertion_point(global_scope)
