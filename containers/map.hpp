#ifndef MAP_HPP
#define MAP_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../utils/pair.hpp"
#include "../utils/is_integral.hpp"

namespace ft
{

	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public :
		
		// 
		// Node
		// 
			struct bt_node
			{
				bt_node *left;
				bt_node *right;
				bt_node *parent;

				ft::pair<const Key, T> data;

				bt_node()
					: right(NULL), left(NULL), parent(NULL) {}

				bt_node(ft::pair<const Key, T> data)
					: left(NULL), right(NULL), parent(NULL), data(data) {}

				const Key &getKey() { return data.first; }
				T &getVal() { return data.second; }
			};

		//
		// Map Iterator
		// 
			template <bool is_const>
			class map_iterator
			{
				public :
					typedef ft::pair<const Key, T> pair_type;
					typedef typename std::conditional<is_const, const pair_type, pair_type>::type value_type;
					typedef typename std::conditional<is_const, const bt_node, bt_node>::type node_type;
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef std::ptrdiff_t difference_type;
					typedef size_t size_type;
					typedef value_type* pointer;
					typedef value_type& reference;

				public :
					node_type *ptr;
					node_type *_end;

				public :

				//
				// Constructor
				// 
					map_iterator() : ptr(NULL), _end(NULL) {}

					map_iterator(node_type *ptr) : ptr(ptr), _end(NULL) {}

					map_iterator(node_type *ptr, node_type *end) : ptr(ptr), _end(end) {}

					map_iterator(const map_iterator<is_const> &src) : ptr(src.ptr), _end(src._end) {}

					map_iterator &operator=(const map_iterator &src) {
						ptr = src.ptr;
						_end = src._end;
						return *this;
					}

					// 
					// Const casting
					// 
					template <bool B>
					map_iterator (const map_iterator<B> & src, typename std::enable_if<!B>::type* = 0) : ptr(src.ptr), _end(src._end) {}

					//
					// Operators
					// 
					node_type *base() const {
						return ptr;
					}

					map_iterator &operator++() {
						if (this->ptr == NULL)
							return *this;
						else if (!this->ptr->parent && !this->ptr->right)
						{
							this->_end = this->ptr;
							this->ptr = NULL;
						}
						else if (this->ptr->right)
							this->ptr = down_bigger_node();
						else
							this->ptr = up_bigger_node(this->ptr);
						return *this;
					}

					map_iterator operator++(int) {
						map_iterator<is_const> tmp = *this;
						this->operator++();
						return tmp;
					}

					map_iterator &operator--() {
						if (this->ptr == NULL)
						{
							if(_end)
								ptr = _end;
						}
						else if (!ptr->parent && !ptr->left)
							ptr = NULL;
						else if (ptr->left)
							ptr = down_smallest_node();
						else
							ptr = up_smallest_node(ptr);
						return *this;
					}

					map_iterator operator--(int) {
						map_iterator<is_const> tmp = *this;
						this->operator--();
						return tmp;
					}

					value_type& operator*() const {
						return ptr->data;
					}

					value_type* operator->() const {
						return &ptr->data;
					}

					template <bool B>
					bool operator==(const map_iterator<B> tocomp) const {
						return ptr == tocomp.base();
					}

					template <bool B>
					bool operator!=(const map_iterator<B> tocomp) const {
						return ptr != tocomp.base();
					}

				private : // Private function like Next and Prev Node // Post order (root is end)
					node_type *up_bigger_node(node_type *node)
					{
						node_type *next;

						if (!node->right)
						{
							next = node;
							if (next->parent->right != next && next != next->parent->left)
								return (NULL);
							while (next->parent != NULL && next == next->parent->right)
								next = next->parent;
							next = next->parent;
						}
						else
						{
							next = node->right;
							while (next->left)
								next = next->left;
						}
						return (next);
					}

					node_type *down_bigger_node()
					{
						node_type *tmp = this->ptr->right;

						while (tmp->left)
							tmp = tmp->left;
						return tmp;
					}

					//Return next smalles
					node_type *down_smallest_node()
					{
						node_type *tmp = this->ptr->left;

						while (tmp->right)
							tmp = tmp->right;
						return tmp;
					}

					node_type *up_smallest_node(node_type *node)
					{
						node_type	*prev;

						if (node->left == NULL || node->left == NULL)
						{
							prev = node;
							while (prev->parent != NULL && prev == prev->parent->left)
								prev = prev->parent;
							prev = prev->parent;
						}
						else
						{
							prev = node->left;
							while (prev->right != NULL)
								prev = prev->right;
						}
						return (prev);
					}
			};

		//
		// Member types
		// 
		public :
			typedef Key     key_type;
			typedef T       mapped_type;
			typedef ft::pair<const key_type, mapped_type>       value_type;
			typedef Compare		key_compare;

		//
		// Value comp (nested class)
		// 
			class value_compare
			{
				friend class map;
				protected :
					key_compare comp;
					value_compare(key_compare c) : comp(c) {}

				public :
					typedef value_type first_arg;
					typedef value_type second_arg;
					bool operator() (const first_arg& x, const second_arg& y) const { return comp(x.first, y.first); }
			};

			typedef typename Alloc::template rebind<bt_node>::other		allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef map_iterator<false>		iterator;
			typedef map_iterator<true>		const_iterator;
			typedef ft::reverse_iterator<iterator>		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename map_iterator<false>::difference_type		difference_type;
			typedef typename map_iterator<false>::size_type		size_type;

		private :
			bt_node *root;
			allocator_type _alloc;
			key_compare _comp;

		public :

		//
		// Constructor
		// 
			explicit map( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: root(NULL), _alloc(alloc), _comp(comp) {
			}

			template< class InputIt >
			map( InputIt first, InputIt last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: root(NULL), _alloc(alloc), _comp(comp) {
					insert(first, last);
			}

			map( const map& other ) : root(NULL), _alloc(other._alloc), _comp(other._comp) {
				clear();
				insert(other.begin(), other.end());
			}

			~map() { clear(); }

			map& operator=( const map& other ) {
				if(this == &other)
					return *this;
				clear();
				insert(other.begin(), other.end());
				_comp = other._comp;
				_alloc = other._alloc;
				return *this;
			}

		// 
		// Iterators
		// 
			iterator begin() {
				return iterator(left_most(root));
			}

			const_iterator begin() const {
				return const_iterator(left_most(root));
			}

			iterator end() {
				return iterator(NULL, right_most(root));
			}

			const_iterator end() const {
				return const_iterator(NULL, right_most(root));
			}

		//
		// Reverse Iterators
		// 
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}

			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}

		// 
		// Capacity
		// 
			bool empty() const {
				return begin() == end();
			}

			size_type size() const {
				return count_node();
			}

			size_type max_size() const {
				return _alloc.max_size();
			}


		// 
		// Element access
		// 
			T& at( const key_type& key ) {
				if(count(key))
				{
					iterator it = find(key);
					return it.base()->getVal();
				}
				else
					throw std::out_of_range("Map : ");
			}

			const T& at( const key_type& key ) const {
				if(count(key))
				{
					iterator it = find(key);
					return it.base().getVal();
				}
				else
					throw std::out_of_range("Map : ");
			}

			mapped_type& operator[] (const key_type& k) {
				(*((this->insert(ft::make_pair(k, mapped_type()))).first));
				return find(k)->second;
			}

		//
		// Modifiers
		// 
			void clear() {
				if(root)
				{
					delete_tree(root);
					root = NULL;
				}
			}

			void swap( map& x ) {
				bt_node *tmp_root = root;
				Compare tmp_cmp = _comp;
				allocator_type tmp_alloc = _alloc;

				root = x.root;
				_comp = x._comp;
				_alloc = x._alloc;

				x.root = tmp_root;
				x._comp = tmp_cmp;
				x._alloc = tmp_alloc;
			}

		//
		// Modifiers Insert
		// 
			ft::pair<iterator, bool> insert (const value_type& val) {
				iterator ite = find(val.first);

				if(count(val.first))
					return ft::make_pair(ite, false);
				else
					return ft::make_pair(iterator(insert_node(val)), true);
			}

			iterator insert (iterator position, const value_type& val) {
				(void)position;
				return insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while(first != last)
					insert(*first++);
			}


			void	transplant( bt_node* oldNode, bt_node* newNode )
			{
				if (!oldNode->parent)
					root = newNode;
				else if (oldNode == oldNode->parent->left)
					oldNode->parent->left = newNode;
				else
					oldNode->parent->right = newNode;
				if (newNode)
					newNode->parent = oldNode->parent;
			}

		//
		// Modifiers Erase
		// 
			void erase (iterator pos) {
				if(pos != end())
					delete_node(pos.base());
			}

			size_type erase (const key_type& k) {
				if(count(k))
				{
					erase(find(k));
					return 1;
				}
				return 0;
			}

			void erase (iterator first, iterator last) {
				while(first != last)
					erase((first++).base());
			}

		//
		// Lookup
		// 
			iterator find (const key_type& k) {
				bt_node *f = find_node(k);
				if(f)
					return iterator(f);
				return end();
			}
			
			const_iterator find (const key_type& k) const {
				bt_node *f = find_node(k);
				if(f)
					return const_iterator(f);
				return end();
			}

			size_type count (const key_type & k) const {
				size_type n = 0;

				if(find(k) == end())
					return n;
				return n + 1;
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
			}

			iterator lower_bound( const Key& key ) {
				iterator it = begin();
				while(it != end())
				{
					if(!(_comp(it->first, key)))
						return it;
					it++;
				}
				return it;
			}

			const_iterator lower_bound( const Key& key ) const {
				const_iterator it = begin();
				while(it != end())
				{
					if(!(_comp(it->first, key)))
						return it;
					it++;
				}
				return it;
			}

			iterator upper_bound( const Key& key ) {
				iterator it = begin();
				while(it != end())
				{
					if((_comp(key, it->first)))
						return it;
					it++;
				}
				return it;
			}

			const_iterator upper_bound( const Key& key ) const {
				const_iterator it = begin();
				while(it != end())
				{
					if((_comp(key, it->first)))
						return it;
					it++;
				}
				return it;
			}


		// 
		// Observers
		// 
			key_compare key_comp() const {
				return _comp;
			}

			value_compare value_comp() const {
				return value_compare(_comp);
			}


			// ! For test
			// void test() {
			// 	print2D(root);
			// 	std::cout << "\n";
			// 	std::cout << "\n";
			// }

		private :

			bt_node *new_node(const value_type &val) {
				bt_node *newnode = _alloc.allocate(1);
				_alloc.construct(newnode, val);
				return newnode;
			}

			bt_node * insert_node(const value_type &val) {
				bt_node *newnode = new_node(val);

				if(root == NULL)
					root = newnode;
				else
				{
					bt_node *r = root;
					while(r)
					{
						if(_comp(r->getKey(), val.first))
						{
							if(!r->right)
							{
								r->right = newnode;
								break;
							}
							r = r->right;
						}
						else
						{
							if(!r->left)
							{
								r->left = newnode;
								break;
							}
							r = r->left;
						}
					}
					newnode->parent = r;
				}
				return newnode;
			}

			bt_node *find_node( const Key &key) const {
				return find_node(root, key);
			}

			bt_node *find_node(bt_node *r, const Key &key) const {
				if(!r || r->getKey() == key) 
					return r;
				if(_comp(key, r->getKey()))
					return find_node(r->left, key);
				return find_node(r->right, key);
			}


			void delete_node(bt_node *ptr) {
				bt_node *tmp = ptr;
				bt_node *x = NULL;

				if(!ptr->left)
				{
					x = ptr->right;
					transplant(ptr, ptr->right);
				}
				else if(!ptr->right)
				{
					x = ptr->left;
					transplant(ptr, ptr->left);				
				}
				else if(ptr->right && ptr->left)
				{
					tmp = left_most(ptr->right);
					x = tmp->right;
					if(tmp->parent == ptr && x)
						x->parent = tmp;
					else
					{
						transplant(tmp, tmp->right);
						tmp->right = ptr->right;
						if(tmp->right)
							tmp->right->parent = tmp;
					}
					transplant(ptr, tmp);
					tmp->left = ptr->left;
					if(tmp->left)
						tmp->left->parent = tmp;
				}
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
			}

		
			size_type count_node() const {
				size_type n = 0;
				for(const_iterator it = begin(); it != end(); it++)
					n++;
				return n;
			}

			bt_node *left_most(bt_node *root) const {
				bt_node *r = root;
				if(!r) return NULL;
				if(!r->left) return r;
				while(r && r->left)
					r = r->left;
				return r;
			}

			bt_node *right_most(bt_node *root) const {
				bt_node *r = root;
				if(!r) return NULL;
				if(!r->right) return r;
				while(r->right)
					r = r->right;
				return r;
			}

			void delete_tree(bt_node *ptr) {
				std::allocator<bt_node> allocate;
				if (ptr->left)
					delete_tree(ptr->left);
				if (ptr->right)
					delete_tree(ptr->right);
				allocate.destroy(ptr);
				allocate.deallocate(ptr, 1);
				ptr = NULL;
			}

			// ! for test ==========
			// #define COUNT 10

			// void print2DUtil(bt_node *root, int space)
			// {
			// 	if (root == NULL)
			// 		return;
			// 	space += COUNT;
			// 	print2DUtil(root->right, space);
			// 	std::cout << std::endl;
			// 	for (int i = COUNT; i < space; i++)
			// 		std::cout<<" ";
			// 	std::cout << root->getKey();
			// 	print2DUtil(root->left, space);
			// }

			// void print2D(bt_node *root)
			// {
			// 	print2DUtil(root, 0);
			// }

	};

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	//
	// Non-member functions (operators)
	// 
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		if(lhs.size() == rhs.size())
		{
			typename ft::map<Key,T,Compare,Alloc>::const_iterator ite_lhs = lhs.begin();
			typename ft::map<Key,T,Compare,Alloc>::const_iterator ite_rhs = rhs.begin();
			while(ite_lhs != lhs.end())
			{
				if(ite_lhs->first != ite_rhs->first || ite_lhs->second != ite_rhs->second)
					return false;
				ite_lhs++, ite_rhs++;
			}
			return true;
		}
		return false;
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

}

#endif