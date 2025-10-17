#ifndef RECOMMENDER_SYSTEM_H_
#define RECOMMENDER_SYSTEM_H_

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

class RecommenderSystem {
 public:
  RecommenderSystem(const std::string& matrixType, int metric, int numNeighbors,
                    int predictionType);

  const std::vector<std::vector<std::string>>& userItemMatrix() const;
  const std::vector<std::vector<std::string>>& userItemMatrixCopy() const;
  int metric() const { return metric_; }
  int numNeighbors() const { return numNeighbors_; }
  int predictionType() const { return predictionType_; }
  double minRating() const { return minRating_; }
  double maxRating() const { return maxRating_; }
  const std::vector<double>& userMean() const { return userMean_; }
  const std::vector<std::vector<double>>& similaritiesPerUser() const;
  const std::vector<std::vector<int>>& neighborsPerUser() const;

  void Recommend();

 private:
  std::vector<std::vector<std::string>> userItemMatrix_, userItemMatrixCopy_;
  int metric_, numNeighbors_, predictionType_;
  double minRating_, maxRating_;
  std::vector<double> userMean_;
  std::vector<std::vector<double>> similaritiesPerUser_;
  std::vector<std::vector<int>> neighborsPerUser_;
  std::vector<std::pair<int, int>> unknownRatingsPerUser_,
      unknownRatingsPerItem_;

  void CalculateUserMean();
  void ChooseNeighbors();

  void CalculateSimilarities();
  double PearsonCorrelation(int user1, int user2) const;
  double CosineSimilarity(int user1, int user2) const;
  double EuclideanDistance(int user1, int user2) const;

  double PredictRating(int user, int item) const;
  double PredictRatingSimple(int user, int item) const;
  double PredictRatingMeanDifference(int user, int item) const;

  void CountUnknownRatingsPerUser();
  void CountUnknownRatingsPerItem();
};

std::ostream& operator<<(std::ostream& os, const RecommenderSystem& rs);

#endif