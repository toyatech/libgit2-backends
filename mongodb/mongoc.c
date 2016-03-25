/*
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2,
 * as published by the Free Software Foundation.
 *
 * In addition to the permissions in the GNU General Public License,
 * the authors give you unlimited permission to link the compiled
 * version of this file into combinations with other programs,
 * and to distribute those combinations without any restriction
 * coming from the use of this file.  (The General Public License
 * restrictions do apply in other respects; for example, they cover
 * modification of the file, and distribution when not linked into
 * a combined executable.)
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <assert.h>
#include <string.h>
#include <git2.h>
#include <git2/sys/odb_backend.h>
#include <git2/sys/refdb_backend.h>
#include <git2/sys/refs.h>
#include <bcon.h>
#include <bson.h>
#include <mongoc.h>

typedef struct {
	git_odb_backend parent;
	// TODO implement

	mongoc_collection_t *objects;
} mongoc_odb_backend;

typedef struct {
	git_refdb_backend parent;
	// TODO implement

	mongoc_collection_t *refs;
} mongoc_refdb_backend;

typedef struct {
	git_reference_iterator parent;
	// TODO implement

} mongoc_refdb_iterator;

static mongoc_client_pool_t *pool = NULL;

/* Odb methods */

int mongoc_odb_backend__read_header(size_t *len_p, git_otype *type_p, 
		git_odb_backend *_backend, const git_oid *oid)
{
	mongoc_odb_backend *backend;
	int error;
        // TODO implement

	error = GIT_ERROR;

        return error;
}

int mongoc_odb_backend__read(void **data_p, size_t *len_p, git_otype *type_p, 
		git_odb_backend *_backend, const git_oid *oid)
{
	mongoc_odb_backend *backend;
	int error;
        // TODO implement

	error = GIT_ERROR;

	return error;
}

int mongoc_odb_backend__read_prefix(git_oid *out_oid, void **data_p,
		size_t *len_p, git_otype *type_p, git_odb_backend *_backend,
		const git_oid *short_oid, size_t len)
{
        // TODO implement

	return GITERR_INVALID;
}

int mongoc_odb_backend__exists(git_odb_backend *_backend, const git_oid *oid)
{
	mongoc_odb_backend *backend;
        int found;
        // TODO implement

        found = 0;

        return found;
}

int mongoc_odb_backend__write(git_odb_backend *_backend, const git_oid *oid,
		const void *data, size_t len, git_otype type)
{
	mongoc_odb_backend *backend;
	int error;
	// TODO implement

	error = GIT_ERROR;

	return error;
}

void mongoc_odb_backend__free(git_odb_backend *_backend)
{
	mongoc_odb_backend *backend;
	// TODO implement

	free(backend);
}

/* Refdb methods */

int mongoc_refdb_backend__exists(int *exists, git_refdb_backend *_backend,
		const char *ref_name)
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK;
	// TODO implement
	
	return error;
}

int mongoc_refdb_backend__lookup(git_reference **out, 
		git_refdb_backend *_backend, const char *ref_name)
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK;
	// TODO implement

	return error;
}

int mongoc_refdb_backend__iterator_next(git_reference **ref,
		git_reference_iterator *_iter) 
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK;
	// TODO implement

	return GIT_ITEROVER;
}

int mongoc_refdb_backend__iterator_next_name(const char **ref_name,
		git_reference_iterator *_iter)
{
	mongoc_refdb_iterator *iter;
	// TODO implement

	return GIT_ITEROVER;
}

void mongoc_refdb_backend__iterator_free(git_reference_iterator *_iter)
{
	mongoc_refdb_iterator *iter;
	// TODO implement

	free(iter);
}

int mongoc_refdb_backend__iterator(git_reference_iterator **_iter,
		struct git_refdb_backend *_backend, const char *glob)
{
	mongoc_refdb_backend *backend;
	mongoc_refdb_iterator *iterator;
	int error = GIT_OK;
	// TODO implement

	return error;
}

int mongoc_refdb_backend__write(git_refdb_backend *_backend,
		const git_reference *ref, int force, const git_signature *who,
		const char *message, const git_oid *old, const char *old_target)
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK;
	// TODO implement

	return error;
}

int mongoc_refdb_backend__rename(git_reference **out, 
		git_refdb_backend *_backend, const char *old_name,
		const char *new_name, const git_signature *who, 
		const char *message)
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK;
	// TODO implement
	
	return error;
}

int mongoc_refdb_backend__del(git_refdb_backend *_backend, const char *ref_name,
		const git_oid *old, const char *old_target)
{
	mongoc_refdb_backend *backend;
	int error = GIT_OK
	// TODO implement

	return error;
}

int mongoc_refdb_backend__free(git_refdb_backend *_backend)
{
	mongoc_refdb_backend *backend;
	// TODO implement

	free(backend);
}

/* reflog methods */

int mongoc_refdb_backend__has_log(git_refdb_backend *_backend, 
		const char *refname)
{
	// TODO implement
	return 0;
}

int mongoc_refdb_backend__ensure_log(git_refdb_backend *_backend,
		const char *refname)
{
	// TODO implement
	return GIT_ERROR;
}

int mongoc_refdb_backend__reflog_read(git_reflog **out, 
		git_refdb_backend *_backend, const char *name)
{
	// TODO implement
	return GIT_ERROR;
}

int mongoc_refdb_backend__reflog_write(git_refdb_backend *_backend, 
		git_reflog *reflog)
{
	// TODO implement
        return GIT_ERROR;
}

int mongoc_refdb_backend__reflog_rename(git_refdb_backend *_backend,
                const char *old_name, const char *new_name)
{
	// TODO implement
        return GIT_ERROR;
}

int mongoc_refdb_backend__reflog_delete(git_refdb_backend *_backend,
                const char *name)
{
	// TODO implement
	return GIT_ERROR;
}

/* Constructors */

int git_odb_backend_mongoc(git_odb_backend **backend_out, 
		const char* collection, const char* path, const char *host,
		int port, char* password)
{
	mongoc_odb_backend *backend;
	// TODO implement

	backend->parent.read = &mongoc_odb_backend__read;
	backend->parent.write = &mongoc_odb_backend__write;
	backend->parent.read_prefix = &mongoc_odb_backend__read_prefix;
	backend->parent.read_header = &mongoc_odb_backend__read_header;
	backend->parent.exists = &mongoc_odb_backend__exists;
	backend->parent.free = &mongoc_odb_backend__free;
	
	*backend_out = (git_odb_backend *) backend;

	return GIT_OK;
}

int git_refdb_backend_mongoc(git_refdb_backend **backend_out,
                const char* collection, const char* path, const char *conn,
                int port, char* password)
{
        mongoc_refdb_backend *backend;
	mongoc_uri_t *uri;
	// TODO implement

	backend = calloc(1, sizeof (mongoc_odb_backend));
	if (backend == NULL)
		return GITERR_NOMEMORY;

	uri = mongoc_uri_new(conn);

	if (pool == NULL) {
		pool = mongoc_client_pool_new (uri);

	backend->parent.exists = &mongoc_refdb_backend__exists;
	backend->parent.lookup = &mongoc_refdb_backend__lookup;
	backend->parent.iterator = &mongoc_refdb_backend__iterator;
	backend->parent.write = &mongoc_refdb_backend__write;
	backend->parent.del = &mongoc_refdb_backend__del;
	backend->parent.rename = &mongoc_refdb_backend__rename;
	backend->parent.compress = NULL;
	backend->parent.free = &mongoc_refdb_backend__free;

	backend->parent.has_log = &mongoc_refdb_backend__has_log;
	backend->parent.ensure_log = &mongoc_refdb_backend__ensure_log;
	backend->parent.reflog_read = &mongoc_refdb_backend__reflog_read;
	backend->parent.reflog_write = &mongoc_refdb_backend__reflog_write;
	backend->parent.reflog_rename = &mongoc_refdb_backend__reflog_rename;
	backend->parent.reflog_delete = &mongoc_refdb_backend__reflog_delete;

	*backend_out = (git_refdb_backend *) backend;

        return GIT_OK;
}
