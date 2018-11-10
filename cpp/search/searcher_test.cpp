#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "searcher.h"

using testing::ElementsAre;

TEST(TestIntSearcher, RangedQuery) {

  IndexConfig config({make_shared<IntFieldConfig>("field1")});
  auto indexer = Indexer(config);
  vector<shared_ptr<Field>> fields;
  for (int i = 0; i < 100; ++i) {
    fields.push_back(make_shared<IntField>(i, "field1", i));
  }
  indexer.index(fields);
  Searcher s1(indexer);
  auto q = make_shared<IntRangeQuery>("field1", 20, 40);
  auto res = s1.query(q);
  ASSERT_EQ(res.size(), 20);
}

TEST(TestIntSearcher, MultiQueryMust) {
  IndexConfig config({make_shared<IntFieldConfig>("field1"),
                      make_shared<IntFieldConfig>("field2")});
  auto indexer = Indexer(config);
  vector<shared_ptr<Field>> fields;
  for (int i = 0; i < 100; ++i) {
    fields.push_back(make_shared<IntField>(i, "field1", i));
    fields.push_back(make_shared<IntField>(i, "field2", i % 10));
  }
  indexer.index(fields);
  Searcher s1(indexer);
  vector<shared_ptr<Query>> queries;
  queries.push_back(make_shared<IntRangeQuery>("field1", 20, 40));
  queries.push_back(make_shared<IntRangeQuery>("field2", 2, 4));
  auto q = make_shared<NestedQuery>(queries, MUST);
  auto res = s1.query(q);
  ASSERT_EQ(res.size(), 4);
}

TEST(TestIntSearcher, MultiQueryShould) {
  IndexConfig config({make_shared<IntFieldConfig>("field1"),
                      make_shared<IntFieldConfig>("field2")});
  auto indexer = Indexer(config);
  vector<shared_ptr<Field>> fields;
  for (int i = 0; i < 100; ++i) {
    fields.push_back(make_shared<IntField>(i, "field1", i));
    fields.push_back(make_shared<IntField>(i, "field2", i * 10));
  }
  indexer.index(fields);
  Searcher s1(indexer);
  vector<shared_ptr<Query>> queries;
  queries.push_back(make_shared<IntRangeQuery>("field1", 20, 40));
  queries.push_back(make_shared<IntRangeQuery>("field2", 390, 410));
  auto q = make_shared<NestedQuery>(queries, SHOULD);
  auto res = s1.query(q);
  ASSERT_EQ(res.size(), 21);
}
TEST(TestStringSearcher, RangedQuery) {
  IndexConfig config({make_shared<StringFieldConfig>("field2")});
  auto indexer = Indexer(config);
  vector<shared_ptr<Field>> fields;
  for (int i = 0; i < 100; ++i) {
    fields.push_back(
        make_shared<StringField>(i, "field2", std::to_string(i % 10)));
  }
  indexer.index(fields);
  Searcher s1(indexer);
  auto q = make_shared<StringQuery>("field2", std::to_string(2));
  auto res = s1.query(q);
  ASSERT_EQ(res.size(), 10);
}
TEST(TestScoredStringSearcher, Query) {
  IndexConfig config(
      {make_shared<StringFieldConfig>("field2", SNOWBALL, true)});
  auto indexer = Indexer(config);
  vector<shared_ptr<Field>> fields;
  vector<vector<string>> s = {{"hello world"}, {"world not cool"}, {"cool"}};
  for (int i = 0; i < s.size(); ++i) {
    fields.push_back(make_shared<StringField>(i, "field2", s[i]));
  }
  indexer.index(fields);
  Searcher s1(indexer);
  auto q = make_shared<StringQuery>("field2", "cool world", true);
  auto res = s1.query(q);
  ASSERT_EQ(res.size(), 3);
  ASSERT_THAT(res, ElementsAre(2, 1, 0));
}
