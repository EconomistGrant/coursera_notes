/**
 * AVL tree - Additional definitions for debugging, etc.
 *
 * @author Eric Huber
 */

#pragma once

#include <stack>

#include "AVL.hpp"

// printInOrder: Print the tree contents to std::cout using an in-order
// traversal. The "_printInOrder" version is for internal use by the
// public wrapper function "printInOrder".
template <typename K, typename D>
void AVL<K, D>::_printInOrder(TreeNode* node) const {
  // Base case: if node is nullptr, then print a space and return.
  if (!node) {
    std::cout << " ";
    return;
  }
  else {
    // Recurse left:
    _printInOrder(node->left);
    // Print this node:
    std::cout << "[" << node->key << " : " << node->data << "]";
    // Recurse right:
    _printInOrder(node->right);
  }
}

// public interface for _printInOrder
template <typename K, typename D>
void AVL<K, D>::printInOrder() const {
  _printInOrder(head_);
}

// Print a simple vertical tree diagram. Indentation shows level,
// and children are listed under parents:
//   parent
//     left child
//     right child
// This repeats iteratively with nested indentation. (This could be done
// recursively as well.)
template <typename K, typename D>
void AVL<K, D>::printVertical() const {

  // Stacks maintain the next node contents to display as well as the
  // corresponding amount of indentation to show in the margin.
  std::stack<TreeNode*> node_stack;
  std::stack<int> margin_stack;

  node_stack.push(head_);
  margin_stack.push(0);

  while (!node_stack.empty()) {

    TreeNode* n = node_stack.top();
    node_stack.pop();

    int margin_level = margin_stack.top();
    margin_stack.pop();

    for (int i=0; i < margin_level; i++) {
      std::cout << " ";
    }

    if (margin_level > 0) {
      std::cout << "|- ";
    }
    else {
      std::cout << ". ";
    }

    if (n) {

      // Only push child markers if at least one child exists.
      // This makes the leaf output clearer: if both children are nullptr,
      // they are simply not printed.
      if (n->left || n->right) {
        node_stack.push(n->right);
        margin_stack.push(margin_level+1);
        node_stack.push(n->left);
        margin_stack.push(margin_level+1);
      }

      // show key, data pair
      std::cout << "[" << n->key << ": \"" << n->data << "\"] ";
      // balance factor
      std::cout << "Bal: " << _get_balance_factor(n) << " ";
      // height
      std::cout << "Ht: " << _get_height(n) << std::endl;
    }
    else {
      // no child (nullptr)
      std::cout << "[]" << std::endl;
    }

  }

}

// These debugging checks do redundant checking just to make sure the
// program doesn't have a mistake that would be hard to catch otherwise.
// In practice this kind of check could be disabled after the library
// was fully tested.

// For practice, think about why the recursive checks in these functions are
// logically valid.

template <typename K, typename D>
bool AVL<K, D>::runDebuggingChecks() {
  if (ENABLE_DEBUGGING_CHECKS) {
    if (!_debugHeightCheck(head_)) throw std::runtime_error("ERROR: _debugHeightCheck failed");
    if (!_debugBalanceCheck(head_)) throw std::runtime_error("ERROR: _debugBalanceCheck failed");
    if (!_debugOrderCheck(head_)) throw std::runtime_error("ERROR: _debugOrderCheck failed");
  }
  return true;
}

template <typename K, typename D>
bool AVL<K, D>::_debugHeightCheck(TreeNode* cur) {

  // a non-existent node implicitly has the correct height
  if (!cur) return true;

  // everything OK left?
  if (!_debugHeightCheck(cur->left)) return false;

  // everything OK right?
  if (!_debugHeightCheck(cur->right)) return false;

  // everything OK here?
  int height_here = _get_height(cur);
  int height_left = _get_height(cur->left);
  int height_right = _get_height(cur->right);
  int max_child_height = std::max(height_left, height_right);
  bool test_result = (1 == height_here - max_child_height);

  if (!test_result) {
    std::cerr << "_debugHeightCheck internals:" << std::endl;
    std::cerr << "here: " << height_here << std::endl;
    std::cerr << "left: " << height_left << std::endl;
    std::cerr << "right: " << height_right << std::endl;
  }
  
  return test_result;
}

template <typename K, typename D>
bool AVL<K, D>::_debugBalanceCheck(TreeNode* cur) {

  // balanced non-existence
  if (!cur) return true;

  // everything OK left?
  if (!_debugBalanceCheck(cur->left)) return false;

  // everything OK right?
  if (!_debugBalanceCheck(cur->right)) return false;

  // everything OK here?
  int bal = _get_height(cur->right) - _get_height(cur->left);
  return (bal >= -1 && bal <= 1);

}

template <typename K, typename D>
bool AVL<K, D>::_debugOrderCheck(TreeNode* cur) {

  if (!cur) return true;

  // This assumes the current implementation does not allow two nodes
  // to have the same key, so we enforce "<" ordering, not "<=" ordering.

  if (cur->left) {
    if (cur->left->key >= cur->key) {
      std::cerr << "ERROR, we found that:" << std::endl;
      std::cerr << "cur->left->key >= cur->key" << std::endl;
      std::cerr << "cur->left->key : " << cur->left->key << std::endl;
      std::cerr << "cur->key : " << cur->key << std::endl;
      return false;
    }
  }

  if (cur->right) {
    if (cur->right->key <= cur->key) {
      std::cerr << "ERROR, we found that:" << std::endl;
      std::cerr << "cur->right->key <= cur->key" << std::endl;
      std::cerr << "cur->right->key : " << cur->right->key << std::endl;
      std::cerr << "cur->key : " << cur->key << std::endl;
      return false;
    }
  }

  return true;
}

