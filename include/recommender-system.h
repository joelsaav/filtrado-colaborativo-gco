#ifndef RECOMMENDER_SYSTEM_H_
#define RECOMMENDER_SYSTEM_H_

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class RecommenderSystem {
 public:
  RecommenderSystem(const std::string& matrixType, int metric, int numNeighbors,
                    int predictionType);

  const std::vector<std::vector<std::string>>& userItemMatrix() const;
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
  std::vector<std::vector<std::string>> userItemMatrix_;
  int metric_;
  int numNeighbors_;
  int predictionType_;
  double minRating_;
  double maxRating_;
  std::vector<double> userMean_;
  std::vector<std::vector<double>> similaritiesPerUser_;
  std::vector<std::vector<int>> neighborsPerUser_;

  std::vector<std::pair<int, int>> unknownRatingsPerUser_;
  std::vector<std::pair<int, int>> unknownRatingsPerItem_;

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